//
// Created by andreas on 18.02.22.
//
#include <cstddef>

struct SomeGoodPrimes
{
	constexpr SomeGoodPrimes() : primes(){
		primes[0] = 53;
		primes[1] = 97;
		primes[2] = 193;
		primes[3] = 389;
		primes[4] = 769;
		primes[5] = 1543;
		primes[6] = 3079;
		primes[7] = 6151;
		primes[8] = 12289;
		primes[9] = 24593;
		primes[10] = 49157;
		primes[11] = 98317;
		primes[12] = 196613;
		primes[13] = 393241;
		primes[14] = 786433;
		primes[15] = 1572869;
		primes[16] = 3145739;
		primes[17] = 6291469;
		primes[18] = 12582917;
		primes[19] = 25165843;
		primes[20] = 50331653;
		primes[21] = 100663319;
		primes[22] = 201326611;
		primes[23] = 402653189;
		primes[24] = 805306457;
		primes[25] = 1610612741;
	}
	size_t primes[26];
};