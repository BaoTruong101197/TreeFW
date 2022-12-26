/**
 * @author Bao
 */

#pragma once

template <typename ...Fn>
class Event
{
public:
    using Callback = std::function<void(Fn...)>;
    Callback callback;
    Event() {

    }

    void on(Callback _callback) {
        callback = std::move(_callback);
    }

    void emit() {
        callback();
    }
};