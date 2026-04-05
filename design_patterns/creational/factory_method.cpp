//
// Created by andreas on 05.04.26.
//
#include <string>

class Vehicle {
public:
    virtual std::string getType() = 0;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
    std::string getType() override {
        return "Car";
    }
};

class Bike : public Vehicle {
public:
    std::string getType() override {
        return "Bike";
    }
};

class Truck : public Vehicle {
public:
    std::string getType() override {
        return "Truck";
    }
};

class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
    virtual ~VehicleFactory() = default;
};

class CarFactory : public VehicleFactory {
    Vehicle* createVehicle() override {
        return new Car();
    }
};

class BikeFactory : public VehicleFactory {
    Vehicle* createVehicle() override {
        return new Bike();
    }
};

class TruckFactory : public VehicleFactory {
    Vehicle* createVehicle() override {
        return new Truck();
    }
};
