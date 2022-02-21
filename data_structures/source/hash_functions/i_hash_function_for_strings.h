//
// Created by andreas on 18.02.22.
//

#ifndef I_HASH_FUNCTION_FOR_STRINGS_H
#define I_HASH_FUNCTION_FOR_STRINGS_H
#include <cstddef>
#include <string>
class IHashFunction
{
public:
	virtual size_t hash(const std::string &string) const = 0;
	virtual size_t prime_number() const = 0;
};

#endif //I_HASH_FUNCTION_FOR_STRINGS_H
