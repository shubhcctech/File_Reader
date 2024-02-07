#include "..\headers\Triangulations.h"


Triangulations::Triangulations()
{
}

Triangulations::~Triangulations()
{
}



std::vector<Points> &Triangulations::uniquePoints()
{
    return mUniquePoints;
}

std::vector<Triangle> &Triangulations::triangles()
{
    return mTriangles;
}