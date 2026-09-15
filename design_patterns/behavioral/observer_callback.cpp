//
// Created by andreas on 15.09.26.
//
#include <functional>
#include <iostream>
#include <unordered_map>

template <typename T>
class CallbackSubject
{
public:
    using Callback = std::function<void(const T&)>;
    using SubscriptionId = std::size_t;
private:
    std::unordered_map<SubscriptionId, Callback> callbacks;
    SubscriptionId next_id{};
public:
     SubscriptionId subscribe(Callback callback)
     {
         const auto id = next_id++;
         callbacks[id] = callback;
         return id;
     }

    void unsubscribe(SubscriptionId id)
    {
        callbacks.erase(id);
    }

    void notify(const T& value)
    {
        for (const auto& [id, callback] : callbacks)
        {
            callback(value);
        }
    }
};

