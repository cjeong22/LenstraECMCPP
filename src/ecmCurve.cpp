#include "../include/ecmCurve.hpp"
#include "../include/inverseException.hpp"
#include <tuple>
#include <iostream>

ECMCurve::ECMCurve(long long p, long long A) : p(p), A(A) {}

std::tuple<long long, long long, long long> ECMCurve::gcd(long long x, long long y) const {
    if (x == 0) {
        return std::make_tuple(y, 0, 1);
    } else {
        long long gcd;
        long long u; 
        long long v;
        std::tie(gcd, u, v) = ECMCurve::gcd(y % x, x);
        return std::make_tuple(gcd, v - (y / x) * u, u);
    }
}

long long ECMCurve::inverse(long long x) {
    long long gcd;
    long long xInverse;
    long long v;
    
    std::tie(gcd, xInverse, v) = ECMCurve::gcd(x, p);
    if (gcd > 1) {
        throw InverseException(gcd);
    }
    return ((xInverse % p) + p) % p;
}

long long ECMCurve::modpow(long long a, long long x) {
    long long res = 1;
    while (x) {
        if (x & 1) {
            res = ((res * a) % p + p) % p;
        }
        a = ((a * a) % p + p) % p;
        x = x >> 1;
    }
    return (res % p + p) % p;
}
long long ECMCurve::getA() {
    return A;
}
long long ECMCurve::getp() {
    return p;
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
    long long lambda;
    if (P.equalTo(Q)) {
        lambda = (((3 * ECMCurve::modpow(P.getX(), 2) + A) * inverse((((P.getY() << 1))))) % p + p) % p;
    } else {
        lambda = (((Q.getY() - P.getY()) * inverse(Q.getX() - P.getX())) % p + p) % p;
    }
    long long resX = ((ECMCurve::modpow(lambda, 2) - Q.getX() - P.getX()) % p + p) % p;
    long long resY = ((lambda * (P.getX() - resX) - P.getY()) % p + p) % p;
    ECMPoint R(resX, resY, false);
    return R;
}

ECMPoint ECMCurve::mult(long long c, ECMPoint P) {
    ECMPoint res(0, 0, true);
    while (c) {
        if (c & 1) {
            res = ECMCurve::add(P, res);
        }
        P = ECMCurve::add(P, P);
        c >>= 1;
    }
    return res;
}