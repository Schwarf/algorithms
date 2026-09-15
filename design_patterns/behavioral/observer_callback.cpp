//
// Created by andreas on 15.09.26.
//
#include <functional>
#include <iostream>
#include <mutex>
#include <unordered_map>

// Advantages:
//   - no Observer base class or inheritance required
//   - supports lambdas, free functions and callable objects
//   - simple unsubscribe via SubscriptionId
//
// Limitations:
//   - callbacks may capture dangling pointers/references
//   - duplicate logical subscriptions are possible
//   - std::function adds type-erasure overhead
//   - not thread-safe
//   - subscribe/unsubscribe during notify() is unsafe
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

// Callback-based Observer implementation.
//
// Improvements:
//   - no Observer base class or inheritance required
//   - supports lambdas, free functions and other callables via std::function
//   - unsubscribe() is simple via SubscriptionId
//   - access to callbacks and next_id is protected by a mutex
//   - notify() works on a snapshot, so callbacks may subscribe/unsubscribe safely
//   - callbacks are invoked after releasing the mutex, avoiding re-entrant deadlocks
//
// Remaining limitations:
//   - callbacks may capture dangling pointers or references; their lifetimes are
//     not managed by BetterCallbackSubject
//   - logically identical callbacks can be subscribed multiple times
//   - std::function adds type-erasure overhead and may allocate dynamically
//   - concurrent notify() calls may execute the same callback concurrently
//   - SubscriptionId may theoretically wrap around after enough subscriptions

template <typename T>
class BetterCallbackSubject
{
public:
    using Callback = std::function<void(const T&)>;
    using SubscriptionId = std::size_t;
private:
    std::unordered_map<SubscriptionId, Callback> callbacks;
    SubscriptionId next_id{};
    std::mutex mutex;
public:

    SubscriptionId subscribe(Callback callback)
    {
        std::lock_guard lock{mutex};
        auto id = next_id++;
        callbacks[id] = callback;
        return id;
    }

    void unsubscribe(SubscriptionId id)
    {
        std::lock_guard lock{mutex};
        callbacks.erase(id);
    }

    void notify(const T & value)
    {
        std::unordered_map<SubscriptionId, Callback> snapshot;
        {
            std::lock_guard lock{mutex};
            snapshot = callbacks;
        }
        for (const auto& [id, callback] : snapshot)
        {
                callback(value);
        }
    }
};

int main()
{
    CallbackSubject<double> sensor;

    auto id = sensor.subscribe(
        [](const double& value)
        {
            std::cout << "Temperature: " << value << '\n';
        });

    sensor.notify(25.5);

    sensor.unsubscribe(id);

    sensor.notify(30.0); // nothing printed
}


