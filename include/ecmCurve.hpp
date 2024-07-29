#include <tuple>
#include "./ecmPoint.hpp"

#ifndef ECMCURVE_H
#define ECMCURVE_H
class ECMCurve {
    private:
        long long p;
        long long A;
    public:
        ECMCurve(long long p, long long A);
        std::tuple<long long, long long, long long> gcd(long long x, long long y) const;
        long long inverse(long long x);
        long long modpow(long long a, long long x);
        long long getA();
        long long getp();
        ECMPoint add(ECMPoint P, ECMPoint Q);
        ECMPoint mult(long long c, ECMPoint P);
};
#endif