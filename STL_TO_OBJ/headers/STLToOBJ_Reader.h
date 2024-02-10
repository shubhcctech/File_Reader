#pragma once

#include <string>
#include <vector>
#include "Triangles.h"
#include"Triangulations.h"

// Class to read Files .stl and .obj.

class STLToOBJ_Reader {
public:
    STLToOBJ_Reader();
    ~STLToOBJ_Reader();
    Triangulations stlReader(const std::string& fileNamePath);   
};

