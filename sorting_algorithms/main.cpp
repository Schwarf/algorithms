#include <algorithm>
#include <iostream>
#include "shell_sort.h"
#include "bitonic_sort.h"

int main() {
    std::vector<int> t{1, 4, 3, 2};
    bitonic_sort<std::vector<int>, 4>(t);
    for (const auto &element: t)
        std::cout << element << ", ";
    std::cout << std::endl;
}