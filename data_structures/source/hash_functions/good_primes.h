//
// Created by andreas on 18.02.22.
//
#include <cstddef>
// Good primes are primes that are far away from powers of 2. E.g. 53 is almost half-way between 32(=2^5) and
// 64(=2^6). The problem with powers of 2 is that e.g. the modulo operation (using a powers of 2, let's day k)
// will just remove the first k bits of the original value and therefore a lot of collisions can be generated.
// A similar bias is expected with numbers close to powers of 2.
// (TODO: CHECK THE STATEMENT ABOVE EXPLICITLY GENERATING HASHES)
namespace Primes
{
constexpr size_t number_of_good_primes = 26;

static constexpr size_t good_primes[Primes::number_of_good_primes] =
	{
		53,
		97,
		193,
		389,
		769,
		1543,
		3079,
		6151,
		12289,
		24593,
		49157,
		98317,
		196613,
		393241,
		786433,
		1572869,
		3145739,
		6291469,
		12582917,
		25165843,
		50331653,
		100663319,
		201326611,
		402653189,
		805306457,
		1610612741
	};
}