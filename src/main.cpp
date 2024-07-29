#include <iostream> 
#include "../include/ecmCurve.hpp"
#include "../include/ecmPoint.hpp"
#include "../include/inverseException.hpp"

int main() {
    ECMCurve curve(97, 2);
    ECMPoint P(17, 10, false);
    ECMPoint Q(95, 31, false);
    ECMPoint R = curve.add(P, Q);
    std::cout << R.getX() << std::endl;
    std::cout << R.getY();
    return 0;
}