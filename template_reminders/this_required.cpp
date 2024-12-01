//
// Created by andreas on 09.05.23.
//
#include <iostream>
template <typename T>
class Base{
public:
	void bar(){
		std::cout << "In bar" << std::endl;
	};
};

template <typename T>
class Derived : Base<T>{
public:
	void foo(){
		// This is required here, does not compile without it.
		this->bar();
		// Alternative
		Base<T>::bar();
	};
};


int main()
{
	auto derived =Derived<int>();
	derived.foo();
	return 0;
}
