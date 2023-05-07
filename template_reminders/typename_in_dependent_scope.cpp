#include <iostream>
#include <vector>

template <typename T>
class MyClass {
public:
	void printSize(T container) {
		// remove typename here will not compile
		typename T::size_type container_size = container.size();
		typename T::value_type first_element =  container[0];
		std::cout << "Size of container: " << container_size << std::endl;
		std::cout << "First element: " << first_element << std::endl;
	}
};

template <typename T>
class MyClass2 {
public:
	// here we can remove typename since we are not in a dependent context
	typename T::value_type getValue(T container) {
		return container.front();
	}
};


int main() {
	std::vector<int> numbers = {1, 2, 3, 4, 5};
	MyClass<std::vector<int>> my;
	MyClass2<std::vector<int>> my2;
	std::cout << "MY2 " << my2.getValue(numbers) << std::endl;
	my.printSize(numbers);
	return 0;
}
