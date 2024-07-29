#include <iostream> 
#include "../include/ecmCurve.hpp"
#include "../include/ecmPoint.hpp"
#include "../include/inverseException.hpp"
#include "../include/lenstraECM.hpp"
#include <vector>
#include <random>

int main() {
    ECMCurve curve(323, rand());
    std::vector<unsigned long> primes;
    primes.push_back(2);
    primes.push_back(3);

    LenstraECM l(curve, 100, 1000);
    std::cout << l.factor(323, primes) << std::endl;
    return 0;
}