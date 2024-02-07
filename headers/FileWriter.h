#include<vector>
#include "Triangles.h"
#include <string>
#include "Triangulations.h"
#include"Points.h"
// Writes .stl and .obj to txt as well as interconvrsion.
class FileWriter
{
    public:
        FileWriter();
        ~FileWriter();
        Triangulations objWrite(const std::string& fileNamePath,Triangulations &tringulation);
        Triangulations stlWrite(const std::string& fileNamePath,Triangulations &tringulation);
        Triangulations stlToObj(const std::string& fileNamePath, Triangulations &triangulation);
        Triangulations objToStl(const std::string& filePathName, Triangulations &traingulation);
        
};
