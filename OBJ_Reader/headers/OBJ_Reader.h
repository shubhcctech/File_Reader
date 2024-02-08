#pragma once
#include"Triangulations.h"
#include <vector>
#include "Triangles.h"
#include <string>

// Class to read Files .stl and .obj.

class OBJ_Reader {
public:
    OBJ_Reader();
    ~OBJ_Reader();
    Triangulations objReader(const std::string& fileNamePath);
    
    
};

