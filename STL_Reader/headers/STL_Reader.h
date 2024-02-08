#ifndef STL_READER_H
#define STL_READER_H
#include"Triangulations.h"
#include <vector>
#include "Triangles.h"
#include <string>

// Class to read Files .stl and .obj.

class STL_Reader {
public:
    STL_Reader();
    ~STL_Reader();
    Triangulations stlReader(const std::string& fileNamePath);
    
    
};

#endif // STL_READER_H