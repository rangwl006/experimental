#pragma once

#include <iostream>
#include <exception>

#include "CreatorPolicies.h"
#include "CheckingPolicies.h"
/**
 * 
*/

namespace design::custom_objects
{
    template<typename T>
    class UniquePtr
    {
        public:
            UniquePtr() : m_ptr(nullptr) {};
            UniquePtr(UniquePtr&& other)
            {
                m_ptr = std::move(other);
            }
            ~UniquePtr();

            // disable copy constructing and assignment operator
            UniquePtr(UniquePtr& other) = delete;
            UniquePtr& operator=(UniquePtr& other) = delete;
            
        private:
            T* m_ptr = nullptr;
    };

    template
    <
       typename ObjectType, 
       template <class> class CheckingPolicy 
    >
    class SmartPtr: public CheckingPolicy<ObjectType>
    {
        public:
            SmartPtr(ObjectType* ptr = nullptr): m_ptr(ptr) {};
            ~SmartPtr() = default;

            ObjectType* localCheck()
            {
                CheckingPolicy<ObjectType>::Check(m_ptr);
                return m_ptr;
            }

        protected:
            ObjectType* m_ptr;
    };
}