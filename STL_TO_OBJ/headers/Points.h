#ifndef POINTS_H
#define POINTS_H

// Coordinates for each point.

class Point3D {
public:

    Point3D();
    Point3D(double xCoordinate, double yCoordinate, double zCoordinate);
    ~Point3D();

    double X() const;
    double Y() const;
    double Z() const;
    bool operator<(const Point3D &pointOther) const;


private:
    double mX;
    double mY;
    double mZ;
};

#endif // POINTS_H
