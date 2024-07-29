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
        unsigned long getPP(int idx);
        std::tuple<long long, long long> factor(std::vector<long long> &primes);
};
#endif