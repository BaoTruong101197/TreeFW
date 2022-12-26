/**
 * @author Bao
 */

#pragma once
#include "core/enums.hpp"
#include "core/event.hpp"
#include <map>
#include<bits/stdc++.h>

template <typename Key = Events, typename ...Fn>
class EventEmitter 
{
private: 
    Event<> event;
    std::map<Events, Event<...Fn>> event_map;
public:
    using Callback = std::function<void(Fn...)>;
    Callback callback;

    void on(Events key, Callback _callback) {
        event.on(_callback);
        event_map.insert(std::pair<Events, Event<>>(key, event));
    }

    void emit(Events key) {
        if (event_map.find(key) != event_map.end()) {
            event_map[key].emit();
        }  
    }   
};