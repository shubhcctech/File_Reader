#pragma once

#include<vector>
#include"Triangles.h"


class Triangulations {
    public:

        Triangulations();
        ~Triangulations();
        std::vector<Point3D> &uniquePoints();
        std::vector<Triangle> &triangles();
        std::vector<Point3D> &uniqueNormalPoints();

    private :
        std::vector<Point3D> mUniquePoints;
        std::vector<Triangle> mTriangles;
        std::vector<Point3D> mUniqueNormalPoints;
};

