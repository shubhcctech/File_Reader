#ifndef POINTS_H
#define POINTS_H
// Coordinates for each point.
class Points {
public:

    Points();
    Points(double xCoordinate, double yCoordinate, double zCoordinate);
    ~Points();

    double X() const;
    double Y() const;
    double Z() const;
    bool operator<(const Points &pointOther) const;


private:
    double mX;
    double mY;
    double mZ;
};

#endif // POINTS_H
