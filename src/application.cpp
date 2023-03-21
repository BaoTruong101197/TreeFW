#include "application.hpp"
#include <bits/stdc++.h>
#include "core/enums.hpp"
#include "logger/logger.hpp"

Application::Application()
{
}

Application::~Application()
{
}

EventEmitter<Events, int> event_emitter;

int Application::main()
{
    LOG(2);

    event_emitter.on(Events::Change, [&](int a) {
        std::cout << "Bao dep trai 2" << a;
    });

    event_emitter.emit(Events::Change, 5);
    return 0;
}