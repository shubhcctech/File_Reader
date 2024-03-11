#pragma once

#include <vector>
#include "Points.h"


class Triangle
{
public:
    Triangle();
    Triangle(const int index);
    Triangle(const int index1, const int index2, const int index3, const int indexNormal);
    ~Triangle();
    int indexNormal() const;
    int index1() const;
    int index2() const;
    int index3() const;
    void setIndexNormal(int indexNormal);
    void setIndex1(int index1);
    void setIndex2(int index2);
    void setIndex3(int index3);

private:
    int mIndexNormal;
    int mIndex1;
    int mIndex2;
    int mIndex3;
};


