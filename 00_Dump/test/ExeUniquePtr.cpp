#include <iostream>

namespace zero
{
    /**
     * Class description:
     * UniquePtr class implements the basic std::unique_ptr
     * 
     * Requirements:
     * 1. the managed object must be deleted when UniquePtr falls out of scope
     * 2. the managed object should be obtainable through a method
     * 3. operator -> should point to the underlying object
     * 4. UniquePtr should not be copyable
     * 5. UniquePtr needs
    */
    class UniquePtr
    {
        public:
            UniquePtr();
            UniquePtr(int* ptr)
            {
                m_pObject = ptr;
            };
            UniquePtr(UniquePtr& other)
            {
                m_pObject = other.Get();
                other.Set(nullptr);
            };

            ~UniquePtr();

            int* Get() const;
            void Set(int* ptr);
        
        private:
            int* m_pObject = nullptr;
    };
}

int main()
{
    std::cout << "ExeUniquePtr" << std::endl;
    return 0;
}