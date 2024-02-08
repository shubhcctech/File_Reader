#ifndef STL_TO_OBJ_READER_H
#define STL_TO_OBJ_READER_H
#include"Triangulations.h"
#include <vector>
#include "Triangles.h"
#include <string>

// Class to read Files .stl and .obj.

class STLToOBJ_Reader {
public:
    STLToOBJ_Reader();
    ~STLToOBJ_Reader();
    Triangulations stlReader(const std::string& fileNamePath);
    
    
};

#endif // STL_READER_H