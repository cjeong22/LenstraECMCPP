#include "ecmCurve.hpp"
#include <map>

#ifndef LENSTRAECM_H
#define LENSTRAECM_H

class LenstraECM {
    private: 
        ECMCurve C;
        long long primeCount;
        long long bound;
        std::vector<long long> boundedPrimes;
        
    public:
        LenstraECM(ECMCurve C, long long primeCount, long long limit);
        void sieve(std::vector<long long> &primes);
        void ppBound(std::vector<long long> &primes);
        std::tuple<long long, long long> factor();
        void multiFactor();
};
#endif