//
// Created by andreas on 17.03.23.
//

#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <cmath>

template <int N, int K>
struct SedgewickSequenceHelper {
	static constexpr int value = SedgewickSequenceHelper<N-1, K>::value;
};

template <int K>
struct SedgewickSequenceHelper<0, K> {
	static constexpr int value = 1;
};

template <int N>
struct SedgewickSequence {
	static constexpr int value = (N % 2 == 0) ? (9 * std::pow(2, N) - 9 * std::pow(2, N/2) + 1) * SedgewickSequenceHelper<N, 0>::value :
								 (8 * std::pow(2, N) - 6 * std::pow(2, (N+1)/2) + 1) * SedgewickSequenceHelper<N, 1>::value;
};


#endif //SHELL_SORT_H
