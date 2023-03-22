//
// Created by andreas on 22.03.23.
//

#ifndef USED_CONCEPTS_H
#define USED_CONCEPTS_H
#include <concepts>
template<typename VertexType>
concept VertexRequirement = !std::is_signed_v<VertexType>;

template<typename EdgeType>
concept EdgeRequirement = std::is_arithmetic_v<EdgeType>;

#endif //USED_CONCEPTS_H
