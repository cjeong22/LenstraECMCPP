#include <tuple>
#include "ecmPoint.hpp"

class ECMCurve {
    private:
        int p;
        int A;
    public:
        ECMCurve(int p, int A);
        std::tuple<int, int, int> gcd(int x, int y) const;
        int inverse(int x);
        ECMPoint add(ECMPoint P, ECMPoint Q);
        ECMPoint mult(int c, ECMPoint P);
};