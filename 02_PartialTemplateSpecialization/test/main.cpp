#include <iostream>

#include "PartialTemplateSpecialization.h"

int main()
{
    int x = 10;
    int y = 9;
    // using fully-specialized compare function
    std::cout << techniques::compare(1.0, 2.0) << std::endl;
    std::cout << techniques::compare(10, 2) << std::endl;

    return 0;
}