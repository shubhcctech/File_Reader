#pragma once


#include<vector>
#include "Triangles.h"
#include <string>
#include "Triangulations.h"
#include"Points.h"

// Writes .stl and .obj to txt as well as interconvrsion.

class OBJ_Writer
{
    public:
        OBJ_Writer();
        ~OBJ_Writer();
        Triangulations objWrite(const std::string& fileNamePath,Triangulations &tringulation);
       
        
};


