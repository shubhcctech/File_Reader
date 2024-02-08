#ifndef STL_WRITER_H
#define STL_WRITER_H

#include<vector>
#include "Triangles.h"
#include <string>
#include "Triangulations.h"
#include"Points.h"

// Writes .stl and .obj to txt as well as interconvrsion.

class STL_Writer
{
    public:
        STL_Writer();
        ~STL_Writer();
        Triangulations stlWrite(const std::string& fileNamePath,Triangulations &tringulation);

};

#endif
