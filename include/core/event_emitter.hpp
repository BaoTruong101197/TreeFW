/**
 * @author BaoTruong
 */

#pragma once
#include "core/enums.hpp"
#include "core/event.hpp"
#include "std/unordered_map.hpp"
#include <bits/stdc++.h>

template <typename Key = Events, typename... Ts>
class EventEmitter
{
public:
    using EventType = Event<Ts...>;
    using EventMap = UMap<Key, EventType>;
    template <Key>
    EventType *getEventType(Key &&key)
    {
        auto it = event_map.find(std::forward<Key>(key));
        return it != event_map.end() ? &it->second : nullptr;
    }
    template <typename K, typename CB>
    void on(K &&key, CB &&_callback)
    {
        getEventType(std::forward<K>(key))->connectCB(std::forward<CB>(_callback));
    } // void emit(Events key) {
    // } private:
    EventMap event_map;
};