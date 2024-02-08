#ifndef OBJ_TO_STL_READER_H
#define OBJ_TO_STL_READER_H
#include"Triangulations.h"
#include <vector>
#include "Triangles.h"
#include <string>

// Class to read Files .stl and .obj.

class OBJToSTL_Reader {
public:
    OBJToSTL_Reader();
    ~OBJToSTL_Reader();
    Triangulations objReader(const std::string& fileNamePath);
    
    
};

#endif // STL_READER_H