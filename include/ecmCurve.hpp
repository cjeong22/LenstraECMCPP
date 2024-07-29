#include <tuple>
#include "./ecmPoint.hpp"

#ifndef ECMCURVE_H
#define ECMCURVE_H
class ECMCurve {
    private:
        int p;
        int A;
    public:
        ECMCurve(int p, int A);
        std::tuple<int, int, int> gcd(int x, int y) const;
        int inverse(int x);
        int modpow(int a, int x);
        ECMPoint add(ECMPoint P, ECMPoint Q);
        ECMPoint mult(int c, ECMPoint P);
};
#endif