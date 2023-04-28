//
// Created by Russell Ang on 11/4/23.
//
#pragma once
#include <string>
#include <vector>

namespace simple
{
  struct HtmlElement
  {
    HtmlElement() = default;
    HtmlElement(const std::string& name, const std::string& text);
    
    std::string str(int indent = 0) const;
    
    std::string m_name;
    std::string m_text;
    std::vector<HtmlElement> m_elements;
  };
  
  class HtmlBuilder
  {
    public:
      
      /**
       * @brief SimpleHtmlBuilder default constructor
       */
      HtmlBuilder() = default;
      
      HtmlBuilder(std::string name);
      
      /**
       * @brief SimpleHtmlBuilder default destructor
       */
      ~HtmlBuilder() = default;
      
      /**
       * @brief add a child to root element
       * @param childName name of child element
       * @param childText text in child element
       */
      void addChild(std::string childName, std::string childText);
      
      std::string str();
    protected:
      HtmlElement root;
  };
  
}