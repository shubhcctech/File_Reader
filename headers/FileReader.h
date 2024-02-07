#ifndef FILE_READER_H
#define FILE_READER_H
#include"Triangulations.h"
#include <vector>
#include "Triangles.h"
#include <string>

class FileReader {
public:
    FileReader();
    ~FileReader();
    Triangulations stlReader(const std::string& fileNamePath);
    Triangulations objReader(const std:: string& fileNamePath);
    
};

#endif // FILE_READER_H
