/**
 * @author BaoTruong
 */

#pragma once
#include "core/enums.hpp"
#include "core/event.hpp"
#include "std/unordered_map.hpp"

template <typename Key = Events, typename... Ts>
class EventEmitter
{
public:
    using EventType = Event<Ts...>;
    using EventMap  = UMap<Key, EventType>;
    Event<> e;

    template <typename K>
    EventType *getEventType(K &&key)
    {
        auto it = event_map.find(std::forward<K>(key));
        return it != event_map.end() ? &it->second : nullptr;
    }

    template <typename K>
    void insertEventKey(K &&key)
    {
        auto* ptr = getEventType(std::forward<K>(key));
        if (!ptr) {
            event_map.insert(std::make_pair(std::forward<K>(key), EventType()));
        }
    }

    template <typename K, typename CB>
    void on(K &&key, CB &&_callback)
    {
        insertEventKey(std::forward<K>(key));
        getEventType(std::forward<K>(key))->connectCB(std::forward<CB>(_callback));
    }

    template <typename K>
    void emit(K &&key, Ts... args)
    {
        EventType *ptr = getEventType(std::forward<K>(key));
        if (ptr)
        {
            ptr->emit(args...);
        }
    }

private:
    EventMap event_map;
};