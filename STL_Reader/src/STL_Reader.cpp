#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "../headers/STL_Reader.h"
#include "../headers/Triangles.h"

// Constructor

STL_Reader::STL_Reader() {}

// Destructor

STL_Reader::~STL_Reader() {}

// Reads stl File.
Triangulations &STL_Reader::stlReader(const std::string &fileNamePath)
{
    std::ifstream inputFile(fileNamePath);
    Triangulations &triangulations = Triangulations::getInstance();
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << fileNamePath << std::endl;
    }
    // Specify Point dimension
    std::vector<Point3D> points;
    std::vector<Triangle> triangles;
    std::map<Point3D, int> pointMap;
    int count = 0;
    int index1;
    int index2;
    int index3;
    std::string line;
    while (std::getline(inputFile, line))
    {
        if (line.find("vertex") != std::string::npos)
        {
            double xCoordinate;
            double yCoordinate;
            double zCoordinate;
            std::string token;
            std::istringstream vertexStream(line);
            vertexStream >> token >> xCoordinate >> yCoordinate >> zCoordinate;
            Point3D point3D(xCoordinate, yCoordinate, zCoordinate);
            auto iterator = pointMap.find(point3D);
            if (iterator == pointMap.end())
            {
                pointMap[point3D] = triangulations.uniquePoints().size();
                triangulations.uniquePoints().push_back(point3D);
            }
            if (count == 0)
            {
                index1 = pointMap[point3D];
                count++;
            }
            else if (count == 1)
            {
                index2 = pointMap[point3D];
                count++;
            }
            else if (count == 2)
            {
                index3 = pointMap[point3D];
                count++;
                triangulations.triangles().push_back(Triangle(index1, index2, index3));
                count = 0;
            }
        }
    }
    std::cout << "Points Reading Completed" << std::endl;
    inputFile.close();
    return triangulations;
}
