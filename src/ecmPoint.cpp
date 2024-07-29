#include "../include/ecmPoint.hpp"

ECMPoint::ECMPoint(const int x, const int y, const bool inf) : x(x), y(y), inf(inf) {}
bool ECMPoint::isInf() const{
    return inf;
}
bool ECMPoint::equalTo(ECMPoint Q) const{
    return (x == Q.getX() && y == Q.getY());
}
int ECMPoint::getX() const{
    return x;
}
int ECMPoint::getY() const{
    return y;
}
