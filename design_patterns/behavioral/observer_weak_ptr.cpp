//
// Created by andreas on 14.09.26.
//

#include <iostream>
#include <memory>
#include <mutex>
#include <vector>

template <typename T>
class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update(const T& value) = 0;
};

// Subject stores weak_ptrs to observers.
// Subject does not own the observers.
// Observers must be owned elsewhere by shared_ptr.
//
// Improvements:
//   - no dangling pointer if an observer is destroyed
//   - expired observers can be detected and removed
//   - duplicate subscriptions are prevented
//   - observers can unsubscribe safely
//   - subscribing/unsubscribing during notify() is safe because notify() operates on a snapshot
//
// Thread safety:
//   - access to observers is protected by a mutex
//   - notify() builds a snapshot while holding the mutex
//   - callbacks are invoked after releasing the mutex
//   - concurrent notify() calls may invoke the same Observer concurrently

// We use std::vector<std::weak_ptr<T>> because before C++26 std::weak_ptr has no
// standard owner-based hash/equality support for straightforward use in std::unordered_set.
template <typename T>
class Subject
{

public:
    void subscribe(const std::shared_ptr<Observer<T>>& observer)
    {

        if (!observer)
            throw std::invalid_argument("observer must not be null");
        std::lock_guard lock(mutex);
        for (auto it = observers.begin(); it != observers.end();)
        {
            if (auto current = it->lock())
            {
                if (current == observer)
                {
                    return;
                }
                ++it;
            }
            else
                it = observers.erase(it);
        }
        observers.push_back(observer);
    }

    void unsubscribe(const std::shared_ptr<Observer<T>>& observer)
    {
        std::lock_guard lock(mutex);
        for (auto it = observers.begin(); it != observers.end();)
        {
            if (auto current = it->lock())
            {
                if (current == observer)
                {
                    it = observers.erase(it);
                    break;
                }
                ++it;
            }
            else
                it = observers.erase(it);
        }
    }

    void notify(const T& value)
    {
        // take a snapshot
        std::vector<std::shared_ptr<Observer<T>>> snapshot_observers;
        {
            std::lock_guard lock(mutex);

            for (auto it = observers.begin(); it != observers.end();)
            {
                if (auto current = it->lock())
                {
                    snapshot_observers.push_back(current);
                    ++it;
                }
                else
                    it = observers.erase(it);
            }
        }
        for (auto& observer : snapshot_observers)
            observer->update(value);

        // for (auto it = observers.begin(); it != observers.end();)
        // {
        //     if (auto observer = it->lock())
        //     {
        //         observer->update(value);
        //         ++it;
        //     }
        //     else
        //     {
        //         it = observers.erase(it);
        //     }
        // }
    }

private:
    std::vector<std::weak_ptr<Observer<T>>> observers;
    std::mutex mutex;
};

class TemperatureDisplay : public Observer<double>
{
public:
    void update(const double& value) override { std::cout << "Temperature: " << value << '\n'; }
};

int main()
{
    Subject<double> sensor;

    auto display = std::make_shared<TemperatureDisplay>();

    sensor.subscribe(display);
    sensor.notify(25.5);
}
