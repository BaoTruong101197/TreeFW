/**
 * @author BaoTruong
 */

#pragma once

#include <vector>
#include <atomic>
#include <functional>

// Event handler
template <typename... Ts>
class Event
{
public:
    using ID = uint32_t;
    using Callback = std::function<void(Ts...)>;
    using PairCBID = std::pair<Callback, ID>;
    using EventList = std::vector<PairCBID>;

    Event()
    {
        counter_id.store(0u);
    }

    Event(const Event<Ts...> &other)
    {
        counter_id.store(0u);
    }

    /**
     * @brief: Disconnect callback with id
     */
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

    /**
     * @brief: Generate new ID with new callback
     */
    ID createNewID()
    {
        return counter_id++;
    }

    /**
     * @brief: Add new callback to callback list
     */
    template <typename Fn>
    void connectCB(Fn &&_callback)
    {
        const auto id = createNewID();
        callbacks.emplace_back(std::forward<Fn>(_callback), id);
    }

    /**
     * @brief: If callback list is not empty. Call all callbacks with params
     */
    void emitEventList(const EventList &_eventList, Ts... params)
    {
        for (auto &event : _eventList)
        {
            event.first(params...);
        }
    }
    void emit(Ts... params)
    {
        if (!empty())
        {
            emitEventList(callbacks, params...);
        }
    }

    /**
     * @brief: Returns the number of callbacks on this event.
     */
    std::size_t size() const
    {
        return callbacks.size();
    }

    /**
     * @brief: Returns true if there are no callbacks on this event.
     */
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