#include "ecmCurve.hpp"
#include <map>

#ifndef LENSTRAECM_H
#define LENSTRAECM_H

class LenstraECM {
    private: 
        ECMCurve C;
        unsigned long primeCount;
        unsigned long bound;

        std::vector<unsigned long> boundedPrimes;
        
    public:
        LenstraECM(ECMCurve C, unsigned long primeCount, unsigned long limit);
        void sieve(std::vector<unsigned long> &primes);
        void ppBound(std::vector<unsigned long> &primes);
        unsigned long getPP(int idx);
        int factor(int N, std::vector<unsigned long> &primes);
};
#endif