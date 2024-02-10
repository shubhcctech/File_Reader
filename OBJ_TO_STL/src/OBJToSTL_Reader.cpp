#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "../headers/OBJToSTL_Reader.h"
#include "../headers/Triangles.h"

// Constructor

OBJToSTL_Reader::OBJToSTL_Reader() {}
// Destructor

OBJToSTL_Reader::~OBJToSTL_Reader() {}

// Reads stl File.

Triangulations OBJToSTL_Reader::objReader(const std::string &fileNamePath)
{
    std::ifstream inputFile(fileNamePath);
    Triangulations triangulationObj;
    std::vector<Point3D> pointObj3D;
    std::vector<Point3D> pointObjNormal3D;
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
            std::string token;
            std::istringstream vertexStream(lineObj);
            vertexStream >> token >> xCoordinate >> yCoordinate >> zCoordinate;
            Point3D points(xCoordinate, yCoordinate, zCoordinate);
            int index = pointObj3D.size();
            pointMapObj[points] = index;
            pointObj3D.push_back(points);
        }
        if (lineObj.find("vn ") != std::string::npos)
        {
            double fNormal;
            double sNormal;
            double tNormal;
            std::string token;
            std::istringstream vertexStream(lineObj);
            vertexStream >> token >> fNormal >> sNormal >> tNormal;

            Point3D pointsNormal(fNormal, sNormal, tNormal);
            pointObjNormal3D.push_back(pointsNormal);
        }
        if (lineObj.find("f ") != std::string::npos)
        {

            double index1;
            double index2;
            double index3;
            double numToken;
            int normalIndex;
            char slash;
            char delim;
            std::string token;
            std::istringstream vertexStream(lineObj);
            vertexStream >> token;
            vertexStream.ignore(256, ' ');
            vertexStream >> index1 >> slash >> numToken >> slash >> normalIndex;
            vertexStream.ignore(256, ' ');
            vertexStream >> index2;
            vertexStream.ignore(256, ' ');
            vertexStream >> index3;
            trianglesObj.push_back(Triangle(index1, index2, index3, normalIndex));
        }
    }

    triangulationObj.normalPoints() = pointObjNormal3D;
    triangulationObj.uniquePoints() = pointObj3D;
    triangulationObj.triangles() = trianglesObj;
    inputFile.close();
    return triangulationObj;
}
