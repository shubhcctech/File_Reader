#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "../headers/OBJ_Reader.h"
#include "../headers/Triangles.h"

// Constructor

OBJ_Reader::OBJ_Reader() {}

// Destructor

OBJ_Reader::~OBJ_Reader() {}

// Reads stl File.
Triangulations OBJ_Reader::objReader(const std::string &fileNamePath)
{
    std::ifstream inputFile(fileNamePath);
    Triangulations triangulationObj;
    std::vector<Point3D> pointObj3D;
    std::vector<Triangle> trianglesObj;
    std::map<Point3D, int> pointMapObj;
    int count = 0;
    std::string lineObj;
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << fileNamePath << std::endl;
    }
    while (std::getline(inputFile, lineObj))
    {
        if (lineObj.find("v ") != std::string::npos)
        {
            double xCoordinate;
            double yCoordinate;
            double zCoordinate;
            std::string tempString;
            std::istringstream vertexStream(lineObj);
            vertexStream >> tempString >> xCoordinate >> yCoordinate >> zCoordinate;
            Point3D points(xCoordinate, yCoordinate, zCoordinate);
            int index = pointObj3D.size();
            pointMapObj[points] = index;
            pointObj3D.push_back(points);
        }
        if (lineObj.find("f ") != std::string::npos)
        {
            std::string fCoordinate;
            std::string sCoordinate;
            std::string tCoordinate;
            std::string tempString;
            std::istringstream vertexStream(lineObj);
            vertexStream >> tempString >> fCoordinate ;
            std::cout<<fCoordinate<<std::endl;
            int index1 = fCoordinate[0] - 48;
            int index2 = sCoordinate[0] - 48;
            int index3 = tCoordinate[0] - 48;
            trianglesObj.push_back(Triangle(index1, index2, index3));
        }
    }
    triangulationObj.uniquePoints() = pointObj3D;
    triangulationObj.triangles() = trianglesObj;
    inputFile.close();
    return triangulationObj;
}

