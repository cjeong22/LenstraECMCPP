#include <iostream> 
#include "../include/ecmCurve.hpp"
#include "../include/ecmPoint.hpp"
#include "../include/inverseException.hpp"
#include "../include/lenstraECM.hpp"
#include <vector>
#include <random>

int main() {
    ECMCurve curve(7071653725825655243LL, rand());
    std::vector<long long> primes;
    primes.push_back(2);
    primes.push_back(3);
    LenstraECM l(curve, 100000, 100000000);
    l.ppBound(primes);
    l.multiFactor();
    return 0;
}