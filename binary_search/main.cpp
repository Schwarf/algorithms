#include <iostream>
#include "binary_search.h"
#include "first_appearance_in_sorted_vector.h"
#include "last_appearance_in_sorted_vector.h"
template<typename T>
void print_type(T value) {
    std::cout << typeid(T).name() << std::endl;
}

int main()
{
	auto x =42;
	print_type(std::type_identity_t<decltype(x)>(x));
}

