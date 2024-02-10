#pragma once
#include <vector>
#include "Points3D.h"

class Triangle {
public:
    Triangle();
    Triangle(const int index1 , const int index2 , const int index3);
    ~Triangle();
    int index1() const;
    int index2() const;
    int index3() const;
    int normalIndex() const;
    void setIndex1(int index1);
    void setIndex2(int index2);
    void setIndex3(int index3);

private:
    int mIndex1;
    int mIndex2;
    int mIndex3;
};
