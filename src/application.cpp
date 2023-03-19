#include "application.hpp"
#include <bits/stdc++.h>

Application::Application()
{
}

Application::~Application()
{
}

Event<> event;
EventEmitter<> event_emitter;

int Application::main()
{
    event_emitter.on(Events::Change, [&] {
        std::cout << "Bao dep trai";
    });

    event_emitter.on(Events::Change, [&] {
        std::cout << "Bao dep trai 1";
    });

    event_emitter.on(Events::Change, [&] {
        std::cout << "Bao dep trai 2";
    });

    event_emitter.emit(Events::Change);
    return 0;
}