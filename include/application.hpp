/**
 * @author Bao Truong
 */

#pragma once
#include <functional> 
#include "core/event.hpp"
#include "core/event_emitter.hpp"
#include "core/enums.hpp"

class Application 
{
private:
    Event<> event;
    EventEmitter<> event_emitter;
public:
    Application();
    ~Application();

    int main();
};