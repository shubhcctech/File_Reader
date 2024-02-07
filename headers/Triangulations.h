#ifndef TRIANGULATIONS_H
#define TRIANGULATIONS_H

#include"Triangles.h"
#include<vector>

class Triangulations {
    public:
        Triangulations();
        ~Triangulations();

        std::vector<Points> &uniquePoints();
        std::vector<Triangle> &triangles();


    private :
        std::vector<Points> mUniquePoints;
        std::vector<Triangle> mTriangles;


};

#endif 