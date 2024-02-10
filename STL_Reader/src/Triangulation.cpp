#include "..\headers\Triangulations.h"

Triangulations::Triangulations()
{
}

Triangulations &Triangulations::getInstance()
{
    static Triangulations instance;
    return instance;
}

std::vector<Point3D> &Triangulations::uniquePoints()
{
    return mUniquePoints;
}

std::vector<Triangle> &Triangulations::triangles()
{
    return mTriangles;
}