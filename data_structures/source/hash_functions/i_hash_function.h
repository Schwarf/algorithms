//
// Created by andreas on 18.02.22.
//

#ifndef I_HASH_FUNCTION_H
#define I_HASH_FUNCTION_H
#include <cstddef>

class IHashFunction
{
	virtual size_t hash(size_t value) const = 0;
};

#endif //I_HASH_FUNCTION_H
