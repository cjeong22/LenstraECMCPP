#include <exception>
#include <string>

using namespace std;
class InverseException : public std::exception {
    private:
        std::string message;
    public:
        int gcd;
        InverseException(int gcd);
};