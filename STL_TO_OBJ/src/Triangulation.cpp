#include "..\headers\Triangulations.h"


Triangulations::Triangulations()
{
}

Triangulations::~Triangulations()
{
}



std::vector<Point3D> &Triangulations::uniquePoints()
{
    return mUniquePoints;
}

std::vector<Triangle> &Triangulations::triangles()
{
    return mTriangles;
}