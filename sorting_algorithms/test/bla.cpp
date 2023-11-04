#include <algorithm>
#include <vector>
#include <functional>
#include <gtest/gtest.h>

template <typename Container>
struct SortingFunction {
	virtual void operator()(typename Container::iterator, typename Container::iterator) const = 0;
};

template <typename Container>
struct S1 : public SortingFunction<Container> {
	void operator()(typename Container::iterator begin, typename Container::iterator end) const override {
		std::sort(begin, end);
	}
};

template <typename Container>
struct S2 : public SortingFunction<Container> {
	void operator()(typename Container::iterator begin, typename Container::iterator end) const override {
		std::sort(begin, end, std::greater<typename Container::value_type>());
	}
};

template <typename Container, typename SortingFunction>
struct SortingTest : public ::testing::Test {
	Container container;
	SortingFunction sortFunction;
};

typedef std::vector<int> IntVector;
typedef ::testing::Types<
	SortingTest<IntVector, S1<IntVector>>,
	SortingTest<IntVector, S2<IntVector>>
> Implementations;

TYPED_TEST_SUITE(Implementations, SortingTest);

TYPED_TEST(Implementations, EmptyContainer) {
	// Test sorting an empty container.
	this->container.clear();
	this->sortFunction(this->container.begin(), this->container.end());
	EXPECT_TRUE(std::is_sorted(this->container.begin(), this->container.end()));
}

TYPED_TEST(Implementations, OneElement) {
	// Test sorting a container with one element.
	this->container = {1};
	this->sortFunction(this->container.begin(), this->container.end());
	EXPECT_TRUE(std::is_sorted(this->container.begin(), this->container.end()));
}
