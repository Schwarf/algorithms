//
// Created by andreas on 05.04.26.
//
#include <string>
#include <iostream>
#include <memory>

class Vehicle {
public:
    virtual std::string getType() const = 0;

    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
    std::string getType() const override {
        return "Car";
    }
};

class Bike : public Vehicle {
public:
    std::string getType() const override {
        return "Bike";
    }
};

class Truck : public Vehicle {
public:
    std::string getType() const override {
        return "Truck";
    }
};

class VehicleFactory {
public:
    virtual std::unique_ptr<Vehicle> createVehicle() const = 0;

    virtual ~VehicleFactory() = default;
};

class CarFactory : public VehicleFactory {
    std::unique_ptr<Vehicle> createVehicle() const override {
        return std::make_unique<Car>();
    }
};

class BikeFactory : public VehicleFactory {
     std::unique_ptr<Vehicle> createVehicle() const override {
        return std::make_unique<Bike>();;
    }
};

class TruckFactory : public VehicleFactory {
    std::unique_ptr<Vehicle> createVehicle() const override {
        return std::make_unique<Truck>();
    }
};

int main() {
    std::unique_ptr<VehicleFactory> carFactory = std::make_unique<CarFactory>();
    std::unique_ptr<VehicleFactory> truckFactory = std::make_unique<TruckFactory>();
    std::unique_ptr<VehicleFactory> bikeFactory = std::make_unique<BikeFactory>();

    auto myCar = carFactory->createVehicle();
    auto myTruck = truckFactory->createVehicle();
    auto myBike = bikeFactory->createVehicle();

    std::cout << myCar->getType() << '\n';
    std::cout << myTruck->getType() << '\n';
    std::cout << myBike->getType() << '\n';
}
