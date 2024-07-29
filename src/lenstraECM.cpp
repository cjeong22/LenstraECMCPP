#include "../include/lenstraECM.hpp"
#include "../include/inverseException.hpp"
#include "../include/ecmCurve.hpp"
#include <vector>
#include <iostream>
#include <random>

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
    if (boundedPrimes.size() == 0) {
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
}

unsigned long LenstraECM::getPP(int idx) {
    return boundedPrimes.at(idx);
}
int LenstraECM::factor(int N, std::vector<unsigned long> &primes) {
    ppBound(primes);
    try {
        srand(time(NULL));
        int x = rand();
        int y = rand();
        ECMPoint P(x, y, false);
        for (unsigned long i = 0; i <= primeCount; i++) {
            int k = boundedPrimes.at(i);
            P = C.mult(k, P);
        }
        return -1;
    } catch (InverseException e) {
        return e.gcd;
    }
}