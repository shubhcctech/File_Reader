#pragma once

#include <string>
#include <vector>
#include "Triangles.h"
#include "Triangulations.h"
#include "Points.h"

// Writes .stl and .obj to txt as well as interconvrsion.

class STLToOBJ_Writer
{
public:

    STLToOBJ_Writer();
    ~STLToOBJ_Writer();
    Triangulations stlObjWrite(const std::string &fileNamePath, Triangulations &tringulation);
};


