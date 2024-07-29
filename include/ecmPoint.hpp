#ifndef ECMPOINT_H
#define ECMPOINT_H

class ECMPoint {
    private:
        int x;
        int y;
        bool inf;
    public:
        ECMPoint(const int x, const int y, const bool inf);
        bool isInf() const;
        bool equalTo(ECMPoint Q) const;
        int getX() const;
        int getY() const;
};

#endif