//
// Created by andreas on 15.09.26.
//
#include <functional>
#include <iostream>
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


