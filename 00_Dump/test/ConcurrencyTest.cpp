//
// Created by Russell Ang on 5/3/23.
//

#include <thread>
#include <iostream>
#include <future>
#include "curl/curl.h"
#include <memory>
#include <fstream>

/*
 * This exercise wraps around the curl handler
 */

class CurlWrapper
{
public:
    CurlWrapper():m_curlHandle(curl_easy_init(), m_curlPtrDeleter) { };
    ~CurlWrapper() = default; // also leave as default for now

    struct CurlPtrDeleter
    {
        void operator()(CURL* handle)
        {
            std::cout << "CurlPtrDeleter" << std::endl;
            curl_easy_cleanup(handle);
        };
    } m_curlPtrDeleter;

    void PullContent(std::string link)
    {
        std::string readBuffer;

        curl_easy_setopt(m_curlHandle.get(), CURLOPT_URL, link.c_str());
        curl_easy_setopt(m_curlHandle.get(), CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(m_curlHandle.get(), CURLOPT_WRITEDATA, &readBuffer);
        CURLcode res = curl_easy_perform(m_curlHandle.get());

        std::ofstream out("/builder/doc.json" );
        out << readBuffer;
//        std::cout << readBuffer << std::endl;
    }
private:
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
    {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    };
    std::unique_ptr<CURL, decltype(m_curlPtrDeleter)> m_curlHandle;
};

int main()
{
    CurlWrapper c;
//    c.PullContent("www.aldo.com");
    c.PullContent("https://data.gov.sg/api/action/datastore_search?resource_id=68289dd4-e9d1-41cf-afe6-b093d04b60af&limit=5");
//    c.PullContent("www.allkpop.com");

    return 0;
};