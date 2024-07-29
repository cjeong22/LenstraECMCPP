#include "ecmCurve.hpp"

#ifndef LENSTRAECM_H
#define LENSTRAECM_H

class LenstraECM {
    private: 
        ECMCurve C;
    public:
        LenstraECM(ECMCurve C);
        void sieve(std::vector<unsigned long> &primes, unsigned long limit);
        int factor(int N);
};
#endif