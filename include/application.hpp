/**
 * @author BaoTruong
 */

#pragma once
#include <functional> 
#include "core/event.hpp"
#include "core/event_emitter.hpp"
#include "core/enums.hpp"

class Application 
{
private:
public:
    Application();
    ~Application();

    int main();
};