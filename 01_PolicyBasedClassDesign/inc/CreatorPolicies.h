#pragma once

#include<iostream>

/**
 * Implementation of policies are called policy classes
 * Policy classes are not meant to be used standalone, but inherited or contained within other classes
 * The classes that inherit or contain the policy classes are called clients
*/

namespace design::custom_objects
{
    struct Widget
    {
        Widget() { std::cout << "Widget created (" << this << ")" << std::endl; };
        ~Widget() { std::cout << "Widget destroyed (" << this << ")" << std::endl; };
    };
}

namespace design::policy
{
    template<class T>
    struct OpNewCreator
    {
        static T* Create()
        {
            return new T;
        };
    };

    template<class T>
    struct MallocCreator
    {
        static T* Create()
        {
            void *buf = malloc(sizeof(T));
            if (!buf) return 0;
            return new(buf) T;
        };
    };

    template<class T>
    class PrototypeCreator
    {
        public:
            PrototypeCreator(T* obj = nullptr): m_prototype(obj) {};

            T Create()
            {
                return m_prototype ? m_prototype->Clone() : nullptr;
            };
            
            T* GetPrototype() { return m_prototype; };
            void SetPrototype(T* pObj) { m_prototype = pObj; }; 
        protected:
            T* m_prototype;
            ~PrototypeCreator() 
            { 
                std::cout << "~PrototypeCreator() deleting m_prototype(" << this << ")" << std::endl;
                delete m_prototype; 
            };
    };
}

namespace design::client
{
    template< class CreationPolicy >
    class GenericManager : public CreationPolicy
    {
        public:
            GenericManager() = default;
            ~GenericManager() = default;
    };

    template
    <
      template< class Object > class CreationPolicy
    >
    class WidgetManager : public CreationPolicy<design::custom_objects::Widget>
    {
        public:
            WidgetManager() = default;
            ~WidgetManager() = default;
            void SwitchPrototype(design::custom_objects::Widget* w)
            {
                CreationPolicy<design::custom_objects::Widget>& myPolicy = *this;
                delete myPolicy.GetPrototype();
                myPolicy.SetPrototype(w);
            }
    };
}