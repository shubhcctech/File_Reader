#ifndef OBJ_TO_STL_WRITER_H
#define OBJ_TO_STL_WRITER_H

#include<vector>
#include "Triangles.h"
#include <string>
#include "Triangulations.h"
#include"Points.h"

// Writes .stl and .obj to txt as well as interconvrsion.

class OBJToSTL_Writer
{
    public:
        OBJToSTL_Writer();
        ~OBJToSTL_Writer();
    
        Triangulations objToStl(const std::string& filePathName, Triangulations &traingulation);
        
};

#endif
