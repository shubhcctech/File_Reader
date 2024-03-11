#pragma once

#include <string>
#include<vector>
#include "Triangles.h"
#include "Triangulations.h"
#include"Points.h"

// Writes .stl and .obj to txt as well as interconvrsion.

class STL_Writer
{
    public:
        STL_Writer();
        ~STL_Writer();
        Triangulations &stlWrite(const std::string& fileNamePath,Triangulations &tringulation);
};

