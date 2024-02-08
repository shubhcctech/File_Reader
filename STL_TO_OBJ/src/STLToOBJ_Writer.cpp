#include "../headers/STLToOBJ_Writer.h"
#include <fstream>
#include <iostream>
#include"../headers/Triangulations.h"
#include "../headers/Triangles.h"
#include "../headers/Points.h"

STLToOBJ_Writer::STLToOBJ_Writer()
{
}
STLToOBJ_Writer::~STLToOBJ_Writer()
{
}

//Reads and writes stl fileinto txt.
Triangulations STLToOBJ_Writer::stlObjWrite(const std::string &filePathName, Triangulations &triangulation)
{
   
    std::ofstream outputFile(filePathName);
    if (!outputFile.is_open())
    {
        throw std::runtime_error("Error opening file for writing: " + filePathName);
    }
    std::vector<Point3D> &points = triangulation.uniquePoints();
    std::vector<Triangle> &triangles = triangulation.triangles();

    outputFile << "o Cube" << std::endl;
    for (const Point3D &points : points)
    {

        outputFile << " v " << points.X() << " " << points.Y() << " " << points.Z() << std::endl;
    }
      outputFile << "" << std::endl;
    for (const Triangle &triangles : triangles)
    {
        outputFile << "f " << triangles.index1()+1 << "//"
                   << " " << triangles.index2()+1<< "//"
                   << " " << triangles.index3()+1<< "//" << std::endl;
    }

    outputFile.close();
    std::cout << "Points written into Obj File" << std::endl;
    return triangulation;
}


