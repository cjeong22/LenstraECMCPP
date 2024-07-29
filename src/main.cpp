#include <iostream> 
#include "../include/ecmCurve.hpp"
#include "../include/ecmPoint.hpp"
#include "../include/inverseException.hpp"

int main() {
    ECMCurve curve(97, 2);
    int n = 2;
    ECMPoint P(3, 6, false);
    ECMPoint R = curve.mult(2, P);
    std::cout << R.getX() << std::endl;
    std::cout << R.getY();
    return 0;
}