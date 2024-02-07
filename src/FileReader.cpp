#include "../headers/FileReader.h"
#include "../headers/Triangles.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

// Constructor
FileReader::FileReader() {}
// Destructor
FileReader::~FileReader() {}

// Reads stl File.
Triangulations FileReader::stlReader(const std::string &fileNamePath)
{
    std::ifstream inputFile(fileNamePath);
    Triangulations triangulation;

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << fileNamePath << std::endl;
    }

    std::vector<Points> points;
    std::vector<Triangle> triangles;
    std::map<Points, int> pointMap;

    int count = 0;
    int index1;
    int index2;
    int index3;
    std::string line;
    while (std::getline(inputFile, line))
    {
        if (line.find("vertex") != std::string::npos)
        {
            double xCoordinate, yCoordinate, zCoordinate;
            std::string temp;
            std::istringstream vertexStream(line);
            vertexStream >> temp >> xCoordinate >> yCoordinate >> zCoordinate;
            Points point1(xCoordinate, yCoordinate, zCoordinate);

            auto iterator = pointMap.find(point1);
            if (iterator == pointMap.end())
            {
                pointMap[point1] = triangulation.uniquePoints().size();
                triangulation.uniquePoints().push_back(point1);
            }

            if (count == 0)
            {
                index1 = pointMap[point1];
                count++;
            }
            else if (count == 1)
            {
                index2 = pointMap[point1];
                count++;
            }
            else if (count == 2)
            {
                index3 = pointMap[point1];
                count++;
                triangulation.triangles().push_back(Triangle(index1, index2, index3));
                count = 0;
            }
        }
    }
    std::cout << "Points Reading Completed" << std::endl;
    inputFile.close();
    return triangulation;
}

// Reads obj File
Triangulations FileReader::objReader(const std::string &filePathName)
{
    std::ifstream inputFile(filePathName);

    Triangulations triangulationObj;
    std::vector<Points> pointsObj;
    std::vector<Triangle> trianglesObj;
    std::map<Points, int> pointMapObj;
    int count = 0;
    std::string lineObj;

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << filePathName << std::endl;
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
            Points points(xCoordinate, yCoordinate, zCoordinate);

            int index = pointsObj.size();
            pointMapObj[points] = index;
            pointsObj.push_back(points);
        }
        if (lineObj.find("f ") != std::string::npos)
        {
            std::string fCoordinate;
            std::string sCoordinate;
            std::string tCoordinate;
            std::string tempString;
            std::istringstream vertexStream(lineObj);

            vertexStream >> tempString >> fCoordinate >> sCoordinate >> tCoordinate;
            int index1 = fCoordinate[0] - 48;
            int index2 = sCoordinate[0] - 48;
            int index3 = tCoordinate[0] - 48;

            trianglesObj.push_back(Triangle(index1, index2, index3));
        }
    }
    triangulationObj.uniquePoints() = pointsObj;
    triangulationObj.triangles() = trianglesObj;
    inputFile.close();
    return triangulationObj;
}
