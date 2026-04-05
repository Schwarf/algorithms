//
// Created by andreas on 05.04.26.
//
#include <string>
#include <iostream>

class Singleton {
private:
    std::string value_;
    Singleton() {}

public:

    static Singleton *getInstance() {
        static Singleton instance;
        return &instance;
    }

    std::string getValue() {
        return value_;
    }

    void setValue(const std::string &value) {
        value_ = value;
    }
};

int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->setValue("Hello Singleton");

    Singleton* s2 = Singleton::getInstance();

    std::cout << "Value from s1: " << s1->getValue() << '\n';
    std::cout << "Value from s2: " << s2->getValue() << '\n';

    if (s1 == s2) {
        std::cout << "s1 and s2 point to the same instance.\n";
    }

    return 0;
}
