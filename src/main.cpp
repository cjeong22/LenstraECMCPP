#include <iostream> 
#include "../include/ecmCurve.hpp"
#include "../include/ecmPoint.hpp"
#include "../include/inverseException.hpp"
#include "../include/lenstraECM.hpp"
#include <vector>

int main() {
    ECMCurve curve(97, 2);
    std::vector<unsigned long> primes;
    primes.push_back(2);
    primes.push_back(3);

    LenstraECM l(curve);
    l.sieve(primes, 100);
    std::cout << primes.at(100) << std::endl;
    return 0;
}