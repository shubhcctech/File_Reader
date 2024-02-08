#include "../headers/STL_Writer.h"
#include <fstream>
#include <iostream>

STL_Writer::STL_Writer()
{
}
STL_Writer::~STL_Writer()
{
}

//Reads and writes stl fileinto txt.
Triangulations STL_Writer::stlWrite(const std::string &filePathName, Triangulations &triangulation)
{
    std::ofstream outputFile(filePathName);
    if (!outputFile.is_open())
    {
        throw std::runtime_error("Error opening file for writing: " + filePathName);
    }
    std::vector<Point3D> &points = triangulation.uniquePoints();
    std::vector<Triangle> &triangles = triangulation.triangles();

    for (const Triangle &triangles : triangles)
    {
        outputFile << points[triangles.index1()].X() << " " << points[triangles.index1()].Y() << " " << points[triangles.index1()].Z() << std::endl;
        outputFile << points[triangles.index2()].X() << " " << points[triangles.index2()].Y() << " " << points[triangles.index2()].Z() << std::endl;
        outputFile << points[triangles.index3()].X() << " " << points[triangles.index3()].Y() << " " << points[triangles.index3()].Z() << std::endl;
        
    }
    outputFile.close();
    std::cout << "Points written into Text File" << std::endl;
    return triangulation;
}


