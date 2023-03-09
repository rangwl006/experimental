#include <iostream>

#include "PartialTemplateSpecialization.h"

int main()
{
    std::cout << "### Start of program" << std::endl;

    int a = 10;

    std::cout << "long int (max) " << std::numeric_limits<long int>::max() << std::endl;
    std::cout << " int     (max) " << std::numeric_limits<int>::max() << std::endl;
    
//    long x = techniques::compile_time_assertions::safe_reinterpret_cast<long>(a);

    std::cout << "### End of program" << std::endl;
    return 0;
}