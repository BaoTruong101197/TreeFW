/**
 * @author BaoTruong
 */

#pragma once

#include <vector>
#include <atomic>
// Event handler
template <typename... Ts>
class Event
{
public:
    using ID = uint8_t;
    using Callback = std::function<void(Ts...)>;
    using PairCBID = std::pair<Callback, ID>;
    using EventList = std::vector<PairCBID>;

    Event()
    {
        counter_id.store(0u);
    }

    void disconnectCB(const ID &id)
    {
        for (std::size_t i = 0; i < callbacks.size(); i++)
        {
            if (callbacks[i].second == id)
            {
                callbacks.erase(i);
            }
        }
    }

    ID createNewID()
    {
        return counter_id++;
    }

    template <typename Fn>
    void connectCB(Fn &&_callback)
    {
        const auto id = createNewID();
        callbacks.emplace_back(std::forward<Fn>(_callback), id);
    }

    void emitEventList(const EventList &_eventList, Ts... params)
    {
        for (std::size_t i = 0; i < _eventList.size(); i++)
        {
            _eventList(params...);
        }
    }

    void emit(Ts... params)
    {
        if (!empty())
        {
            emitEventList(params...);
        }
    }

    // Returns the number of callbacks on this event.
    std::size_t size() const
    {
        return callbacks.size();
    }

    // Returns true if there are no callbacks on this event.
    bool empty() const

    {
        return callbacks.empty();
    }

private:
    EventList callbacks;
    /**
     * @details: atomic - offers thread-safe, avoid data race
     * @brief: unique IDs to count.
     */
    std::atomic<ID> counter_id;
};