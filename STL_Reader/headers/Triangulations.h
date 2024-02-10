#pragma once

#include <vector>
#include "Triangles.h"

// To increase the efficiency .

class Triangulations
{
public:

    static Triangulations &getInstance();
    std::vector<Point3D> &uniquePoints();
    std::vector<Triangle> &triangles();

private:

    Triangulations();
    std::vector<Point3D> mUniquePoints;
    std::vector<Triangle> mTriangles;
    Triangulations(const Triangulations &obj) = delete;
};
