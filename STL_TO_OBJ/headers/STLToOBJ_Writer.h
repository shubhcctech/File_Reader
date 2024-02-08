#ifndef STL_TO_OBJ_WRITER_H
#define STL_TO_OBJ_WRITER_H

#include<vector>
#include "Triangles.h"
#include <string>
#include "Triangulations.h"
#include"Points.h"

// Writes .stl and .obj to txt as well as interconvrsion.

class STLToOBJ_Writer
{
    public:
        STLToOBJ_Writer();
        ~STLToOBJ_Writer();
        Triangulations stlObjWrite(const std::string& fileNamePath,Triangulations &tringulation);
       
        
};

#endif
