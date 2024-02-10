#pragma once
#include <string>
#include <vector>
#include "Triangles.h"
#include"Triangulations.h"

// Class to read Files .stl and .obj.

class OBJToSTL_Reader {
public:
    OBJToSTL_Reader();
    ~OBJToSTL_Reader();
    Triangulations objReader(const std::string& fileNamePath); 
};

