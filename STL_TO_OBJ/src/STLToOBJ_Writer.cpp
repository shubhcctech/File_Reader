#include <fstream>
#include <iostream>
#include "../headers/STLToOBJ_Writer.h"
#include "../headers/Triangulations.h"
#include "../headers/Triangles.h"
#include "../headers/Points.h"

STLToOBJ_Writer::STLToOBJ_Writer()
{
}
STLToOBJ_Writer::~STLToOBJ_Writer()
{
}

// Reads and writes stl fileinto txt.
Triangulations STLToOBJ_Writer::stlObjWrite(const std::string &filePathName, Triangulations &triangulation)
{

    std::ofstream outputFile(filePathName);
    if (!outputFile.is_open())
    {
        throw std::runtime_error("Error opening file for writing: " + filePathName);
    }
    std::vector<Point3D> &points = triangulation.uniquePoints();
    std::vector<Triangle> &triangles = triangulation.triangles();
    std::vector<Point3D> &normals = triangulation.uniqueNormalPoints();

    outputFile << "o Cube" << std::endl;
    for (const Point3D &points : points)
    {

        outputFile << " v " << points.X() << " " << points.Y() << " " << points.Z() << std::endl;
    }
    outputFile << "" << std::endl;
    for (int i = 0; i < normals.size(); i++)
    {
        outputFile << "vn " << normals[i].X() << " " << normals[i].Y() << " " << normals[i].Z() << std::endl;
    }
    for (const Triangle &triangles : triangles)
    {
        outputFile << "f " << triangles.index1() + 1 << "//" << triangles.indexNormal()
                   << " " << triangles.index2() + 1 << "//" << triangles.indexNormal()
                   << " " << triangles.index3() + 1 << "//" << triangles.indexNormal() << std::endl;
    }

    outputFile.close();
    std::cout << "Points written into Obj File" << std::endl;
    return triangulation;
}
