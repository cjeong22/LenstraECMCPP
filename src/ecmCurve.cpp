#include "../include/ecmCurve.hpp"
#include "../include/inverseException.hpp"
#include <iostream>
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
        return std::make_tuple(gcd, v - (y / x) * u, u);
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

int ECMCurve::modpow(int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) {
            res = ((res * a) % p + p) % p;
        }
        a = ((a * a) % p + p) % p;
        x = x >> 1;
    }
    return (res % p + p) % p;
}

ECMPoint ECMCurve::add(ECMPoint P, ECMPoint Q) {
    if (P.isInf()) {
        return Q;
    }
    if (Q.isInf()) {
        return P;
    }
    if (P.getX() == Q.getX() && P.getY() == -Q.getY()) {
        ECMPoint R(0, 0, true);
        return R;
    }
    int lambda;
    if (P.equalTo(Q)) {
        lambda = (((3 * ECMCurve::modpow(P.getX(), 2) + A) * inverse((((P.getY() << 1))))) % p + p) % p;
    } else {
        lambda = (((Q.getY() - P.getY()) * inverse(Q.getX() - P.getX())) % p + p) % p;
    }
    int resX = ((ECMCurve::modpow(lambda, 2) - Q.getX() - P.getX()) % p + p) % p;
    int resY = ((lambda * (P.getX() - resX) - P.getY()) % p + p) % p;
    ECMPoint R(resX, resY, false);
    return R;
}