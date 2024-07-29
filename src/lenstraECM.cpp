#include "../include/lenstraECM.hpp"
#include <vector>
#include <iostream>

#define MAXLEN 1UL << 62

LenstraECM::LenstraECM(ECMCurve C, unsigned long primeCount, unsigned long bound) : C(C), primeCount(primeCount), bound(bound) {}

// primes is guaranteed to have 2, 3 upon passing in
void LenstraECM::sieve(std::vector<unsigned long> &primes) {
    while (primes.size() <= primeCount) {
        for (unsigned long i = primes.back() + 2; i < MAXLEN; i += 2) {
            bool isPrime = true;
            for (int prime : primes) {
                if (prime * prime > i) {
                    break;
                }
                if (!(i % prime)) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                primes.push_back(i);
                break;
            }
        }
    }
}
void LenstraECM::ppBound(std::vector<unsigned long> &primes) {
    sieve(primes);
    for (unsigned long i = 0; i <= primeCount; i++) {
        int p = primes.at(i);
        if (p >= bound) {
            break;
        }
        int base = p;
        while (1) {
            base = base * p;
            if (base >= bound) {
                base /= p;
                break;
            }
        }
        boundedPrimes.push_back(base);
    }
}

unsigned long LenstraECM::getPP(int idx) {
    return boundedPrimes.at(idx);
}
int factor(int N) {

}