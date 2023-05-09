//
// Created by andreas on 07.05.23.
//
#include <iostream>

template <typename T>
class MyClass {
public:
	template <typename U>
	void foo(U value) {
		T::template bar<U>(value);
	}
};

class MyType {
public:
	template <typename U>
	static void bar(U value) {
		std::cout << "bar: " << value << std::endl;
	}
};


template <typename T>
class Outer {
public:
	template <typename U>
	class Nested {
	public:
		void foo() {
			typename T::template Inner<U>::type variable;
			std::cout << "foo: " << typeid(variable).name() << std::endl;
		}
	};
};

template <typename T>
struct Inner {
	using type = T;
};


int main() {
	MyClass<MyType> obj;
	obj.foo(42);

	Outer<Inner<int>> out;
	Outer<Inner<int>>::Nested<int> nestedObj;
	nestedObj.foo();
	return 0;
}
