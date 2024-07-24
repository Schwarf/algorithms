#include <iostream>
#include "../dynamic_programming/maximum_subarray_kadane_algorithm.h"

int main() {
    std::vector<float> h{1, 2, 3, 4, 4};

    std::cout << maximum_subarray_kadane_algorithm(h, 0.F) << std::endl;
    return 0;
}
