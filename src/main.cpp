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

    LenstraECM l(curve, 100, 100);
    l.ppBound(primes);
    std::cout << l.getPP(1) << std::endl;
    return 0;
}