/**
 *
 * @author Bao Truong
 */

#include "application.hpp"
#include "logger/logger.hpp"
#include "core/node.hpp"

Application::Application()
{
}

Application::~Application()
{
}

int Application::main()
{
    FieldNode a;
    Node *ptr = new Node(a);

    FieldNode b(ptr);
    Node *ptr1 = new Node(b);

    FieldNode c(ptr);
    Node *ptr2 = new Node(c);

    ptr->forEachChild([&](auto* child) {
        LOG("CCC");
    });

    return 0;
}