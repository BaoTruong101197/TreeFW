/**
 *
 * @author Bao Truong
 */


#include "application.hpp"
#include "core/enums.hpp"
// #include "logger/logger.hpp"
#include "core/tree.hpp"
#include <iostream>

Application::Application()
{
}

Application::~Application()
{
}

int Application::main()
{
    Tree ptr;
    Tree ptr1(&ptr);
    Tree ptr2(&ptr);
    Tree ptr3(&ptr1);
    Tree ptr4(&ptr2);
    Tree ptr5(&ptr2);

    if (ptr.getChild("1"))
    {
        std::cout << ptr.getChild("1")->getName();
    }
    else 
    {
        std::cout << "AAAAA";
    }
    
    // ptr.forEachChild();
    ptr.forEachChild([&](auto* child) {
        std::cout << child->getName();
    });
    
    
    return 0;
}