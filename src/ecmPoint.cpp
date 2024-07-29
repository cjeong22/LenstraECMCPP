#include "../include/ecmPoint.hpp"

ECMPoint::ECMPoint(const long long x, const long long y, const bool inf) : x(x), y(y), inf(inf) {}
bool ECMPoint::isInf() const{
    return inf;
}
bool ECMPoint::equalTo(ECMPoint Q) const{
    return (x == Q.getX() && y == Q.getY());
}
long long ECMPoint::getX() const{
    return x;
}
long long ECMPoint::getY() const{
    return y;
}
