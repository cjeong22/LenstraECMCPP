#ifndef ECMPOINT_H
#define ECMPOINT_H

class ECMPoint {
    private:
        long long x;
        long long y;
        bool inf;
    public:
        ECMPoint(const long long x, const long long y, const bool inf);
        bool isInf() const;
        bool equalTo(ECMPoint Q) const;
        long long getX() const;
        long long getY() const;
};

#endif