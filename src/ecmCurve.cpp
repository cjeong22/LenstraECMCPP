#include "../include/ecmCurve.hpp"
#include "../include/inverseException.hpp"
#include <tuple>

ECMCurve::ECMCurve(int p, int A) : p(p), A(A) {}

std::tuple<int, int, int> ECMCurve::gcd(int x, int y) const {
    if (x == 0) {
        return std::make_tuple(y, 0, 1);
    } else {
        int gcd;
        int u; 
        int v;
        std::tie(gcd, u, v) = ECMCurve::gcd(y % x, x);
        return std::make_tuple(gcd, v - y / x, u);
    }
}

int ECMCurve::inverse(int x) {
    int gcd;
    int xInverse;

    std::tie(gcd, xInverse, std::ignore) = ECMCurve::gcd(x, p);
    if (gcd > 1) {
        throw InverseException(gcd);
    }
    return ((xInverse % p) + p) % p;
}