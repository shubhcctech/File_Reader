#ifndef TRIANGULATIONS_H
#define TRIANGULATIONS_H

#include"Triangles.h"
#include<vector>

class Triangulations {
    public:
        Triangulations();
        ~Triangulations();
        std::vector<Point3D> &normalPoints();
        std::vector<Point3D> &uniquePoints();
        std::vector<Triangle> &triangles();
        std::vector<Triangle> &trianglesNormal();


    private :
        std::vector<Point3D> mNormalPoints;
        std::vector<Point3D> mUniquePoints;
        std::vector<Triangle> mTriangles;
        std::vector<Triangle> mTrianglesNormal;
        


};

#endif 