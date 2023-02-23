#include <iostream>

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

        private:
        
    }
}

namespace design::policy::func
{
    struct OpNewCreator
    {
        template<typename T>
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
}

namespace design::custom_objects
{
    struct Widget
    {
        Widget() {std::cout << "Widget created: " << this << std::endl; };
        ~Widget() { std::cout << "Widget deleted: " << this << std::endl; };
        int width = 160;
        int height = 90;

    };
}

namespace design::user
{
    // define some code here which uses the creation policy
    template<class CreationPolicy>
    class GenericManager : public CreationPolicy // template has not yet been specialized
    {
        public:
            GenericManager()  = default;
            ~GenericManager() = default;
    };

    template< template< class Object > class CreationPolicy >
    class WidgetManager : public CreationPolicy<design::custom_objects::Widget> // template has already been specialized
    {
        public:
            WidgetManager()  = default;
            ~WidgetManager() = default;
    };
}
