//
// Created by andreas on 05.04.26.
//

#include <iostream>
#include <string>
class Meal {
private:
    double cost;
    bool takeOut;
    std::string main;
    std::string drink;

public:
    double getCost() {
        return cost;
    }

    bool getTakeOut() {
        return takeOut;
    }

    std::string getMain() {
        return main;
    }

    std::string getDrink() {
        return drink;
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    void setTakeOut(bool takeOut) {
        this->takeOut = takeOut;
    }

    void setMain(const std::string & main) {
        this->main = main;
    }

    void setDrink(const std::string & drink) {
        this->drink = drink;
    }
};

class MealBuilder {
private:
    Meal meal;

public:
    MealBuilder() {
    }

    MealBuilder& addCost(double cost) {
        meal.setCost(cost);
        return *this;
    }

    MealBuilder& addTakeOut(bool takeOut) {
        meal.setTakeOut(takeOut);
        return *this;
    }

    MealBuilder& addMainCourse(const std::string& main) {
        meal.setMain(main);
        return *this;
    }

    MealBuilder& addDrink(const std::string& drink) {
        meal.setDrink(drink);
        return *this;
    }

    Meal build() {
        return meal;
    }
};

int main() {
    Meal meal = MealBuilder()
        .addMainCourse("Burger")
        .addDrink("Cola")
        .addTakeOut(true)
        .addCost(12.5)
        .build();

    std::cout << "Meal details:\n";
    std::cout << "Main course: " << meal.getMain() << '\n';
    std::cout << "Drink: " << meal.getDrink() << '\n';
    std::cout << "Take out: " << (meal.getTakeOut() ? "Yes" : "No") << '\n';
    std::cout << "Cost: " << meal.getCost() << '\n';

    return 0;
}