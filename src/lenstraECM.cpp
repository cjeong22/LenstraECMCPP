#include "../include/lenstraECM.hpp"
#include <vector>
#include <iostream>

#define MAXLEN 1UL << 62

LenstraECM::LenstraECM(ECMCurve C) : C(C) {}

// primes is guaranteed to have 2, 3 upon passing in
void LenstraECM::sieve(std::vector<unsigned long> &primes, unsigned long limit) {
    while (primes.size() <= limit) {
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
int factor(int N) {

}