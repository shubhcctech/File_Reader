#include <fstream>
#include <iostream>
#include "../headers/OBJToSTL_Writer.h"

OBJToSTL_Writer::OBJToSTL_Writer()
{
}
OBJToSTL_Writer::~OBJToSTL_Writer()
{
}

// Reads and writes stl fileinto txt.

Triangulations OBJToSTL_Writer::objToStl(const std::string &filePathName, Triangulations &triangulation)
{
    std::ofstream outputFile(filePathName);
    if (!outputFile.is_open())
    {
        throw std::runtime_error("Error opening file for writing: " + filePathName);
    }
    std::vector<Point3D> &pointsNormal = triangulation.normalPoints();
    std::vector<Point3D> &points = triangulation.uniquePoints();
    std::vector<Triangle> &triangles = triangulation.triangles();
    std::vector<Triangle> &trianglesNormal = triangulation.trianglesNormal();
    outputFile << "solid" << std::endl;
    for (const Triangle &triangles : triangles)
    {
        outputFile << " facet normal " << pointsNormal[triangles.indexNormal() - 1].X() << " " << pointsNormal[triangles.indexNormal() - 1].Y() << " " << pointsNormal[triangles.indexNormal() - 1].Z() << std::endl;
        outputFile << "  outer loop" << std::endl;
        outputFile << " vertex " << points[triangles.index1() - 1].X() << " " << points[triangles.index1() - 1].Y() << " " << points[triangles.index1() - 1].Z() << std::endl;
        outputFile << " vertex " << points[triangles.index2() - 1].X() << " " << points[triangles.index2() - 1].Y() << " " << points[triangles.index2() - 1].Z() << std::endl;
        outputFile << " vertex " << points[triangles.index3() - 1].X() << " " << points[triangles.index3() - 1].Y() << " " << points[triangles.index3() - 1].Z() << std::endl;
        outputFile << "  endloop" << std::endl;
        outputFile << " endfacet" << std::endl;
    }
    outputFile << "endsolid" << std::endl;
    outputFile.close();
    std::cout << "Points written into Stl File" << std::endl;
    return triangulation;
}
