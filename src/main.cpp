#include <iostream> 
#include "ecmCurve.cpp"
int main() {
    ECMCurve curve(6, 2);
    try{
        std::cout << (curve.inverse(5));
    } catch (const InverseException e) {
        std::cout << (e.gcd);
    }
    return 0;
}