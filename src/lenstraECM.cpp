#include "../include/lenstraECM.hpp"
#include "../include/inverseException.hpp"
#include "../include/ecmCurve.hpp"
#include <unistd.h>
#include <vector>
#include <iostream>
#include <random>

#define MAXLEN 1UL << 62

LenstraECM::LenstraECM(ECMCurve C, long long primeCount, long long bound) : C(C), primeCount(primeCount), bound(bound) {}

// primes is guaranteed to have 2, 3 upon passing in
void LenstraECM::sieve(std::vector<long long> &primes) {
    while (primes.size() <= primeCount) {
        for (long long i = primes.back() + 2; i < MAXLEN; i += 2) {
            bool isPrime = true;
            for (long long prime : primes) {
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
void LenstraECM::ppBound(std::vector<long long> &primes) {
    if (boundedPrimes.size() == 0) {
        std::cout << "generating" << std::endl;
        sieve(primes);
        for (long long i = 0; i <= primeCount; i++) {
            long long p = primes.at(i);
            if (p >= bound) {
                break;
            }
            long long base = p;
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

std::tuple<long long, long long> LenstraECM::factor() {
    try {
        srand(time(NULL));
        int x = rand();
        int y = rand();
        ECMPoint P(x, y, false);
        for (long long i = 0; i <= primeCount; i++) {
            int k = boundedPrimes.at(i);
            P = C.mult(k, P);
        }
        return std::make_tuple(-1, -1);
    } catch (InverseException e) {
        return std::make_tuple(e.gcd, C.getA() / e.gcd);
    }
}

void LenstraECM::multiFactor() {
    for (int i = 0; i < 8; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            std::cout << std::get<0>(LenstraECM::factor()) << std::endl;
            return;
        }
    }
}