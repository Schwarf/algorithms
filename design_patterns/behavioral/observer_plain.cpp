//
// Created by andreas on 14.09.26.
//
// Subject
//   - stores a list of observers
//   - allows observers to subscribe
//   - notifies all observers
//
// Observer
//   - defines the interface that concrete observers must implement
//
// ConcreteObserver
//   - implements the notification behavior

#include <iostream>
#include <unordered_set>
#include <vector>

template <typename T>
class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update(const T& value) = 0;
};

// Subject stores non-owning pointers to observers.
// Destroying the Subject does not destroy the observers.
// Limitations:
// - no unsubscribe(): destroying an observer while it is still registered leaves a dangling pointer
// - the same observer can be subscribed multiple times
// - nullptr is currently accepted by subscribe()
// - not thread-safe
template <typename T>
class Subject
{
public:
    void subscribe(Observer<T>* observer)
    {
        observers.push_back(observer);
    }

    void notify(const T& value)
    {
        for (auto observer : observers)
        {
            observer->update(value);
        }
    }


private:
    std::vector<Observer<T>*> observers;
};

// BetterSubject stores non-owning pointers to observers.
// Destroying the BetterSubject does not destroy the observers.
// Limitations:
// - lifetime safety: if an Observer is destroyed without first unsubscribing, BetterSubject keeps a dangling pointer
// - not thread-safe
// - subscribing/unsubscribing during notify() is unsafe
template <typename T>
class BetterSubject
{
public:
    void subscribe(Observer<T>* observer)
    {
        if (observer == nullptr)
            throw std::invalid_argument("observer must not be nullptr");

        observers.insert(observer);
    }

    void unsubscribe(Observer<T>* observer)
    {
        observers.erase(observer);
    }

    void notify(const T& value)
    {
        for (auto * observer : observers)
        {
            observer->update(value);
        }
    }


private:
    std::unordered_set<Observer<T>*> observers;
};

// Concrete Observer
class TemperatureDisplay: public Observer<double>
{
public:
    void update(const double& value) override
    {
        std::cout << "Temperature: " << value << std::endl;
    }

};

int main()
{
    BetterSubject<double> sensor;
    TemperatureDisplay display;
    sensor.subscribe(&display);
    sensor.notify(25.5);
}
