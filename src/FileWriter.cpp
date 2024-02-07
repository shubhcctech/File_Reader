#include "../headers/FileWriter.h"
#include <fstream>
#include <iostream>

FileWriter::FileWriter()
{
}
FileWriter::~FileWriter()
{
}

//Reads and write obj file into txt.
Triangulations FileWriter::objWrite(const std::string &filePathName, Triangulations &triangulation)
{
    std::ofstream outputFile(filePathName);
    if (!outputFile.is_open())
    {
        throw std::runtime_error("Error opening file for writing: " + filePathName);
    }
    std::vector<Points> &points = triangulation.uniquePoints();
    std::vector<Triangle> &triangles = triangulation.triangles();

    for (const Triangle &triangles : triangles)
    {

        outputFile << points[triangles.index1() - 1].X() << " " << points[triangles.index1() - 1].Y() << " " << points[triangles.index1() - 1].Z() << std::endl;
        outputFile << points[triangles.index2() - 1].X() << " " << points[triangles.index2() - 1].Y() << " " << points[triangles.index2() - 1].Z() << std::endl;
        outputFile << points[triangles.index3() - 1].X() << " " << points[triangles.index3() - 1].Y() << " " << points[triangles.index3() - 1].Z() << std::endl;
    }

    outputFile.close();
    std::cout << "Points written into Text File" << std::endl;
    return triangulation;
}





//Reads and writes stl fileinto txt.
Triangulations FileWriter::stlWrite(const std::string &filePathName, Triangulations &triangulation)
{
    std::ofstream outputFile(filePathName);
    if (!outputFile.is_open())
    {
        throw std::runtime_error("Error opening file for writing: " + filePathName);
    }
    std::vector<Points> &points = triangulation.uniquePoints();
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




//Reads obj file and writes it into stl file
Triangulations FileWriter::objToStl(const std::string &filePathName, Triangulations &triangulation)
{
    std::ofstream outputFile(filePathName);
    if (!outputFile.is_open())
    {
        throw std::runtime_error("Error opening file for writing: " + filePathName);
    }
    std::vector<Points> &points = triangulation.uniquePoints();
    std::vector<Triangle> &triangles = triangulation.triangles();
    outputFile << "solid" << std::endl;

    for (const Triangle &triangles : triangles)
    {
        outputFile << " facet normal" << std::endl;
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




//Reads stl file and writes into obj file
Triangulations FileWriter::stlToObj(const std::string &filePathName, Triangulations &triangulation)
{
    std::ofstream outputFile(filePathName);
    if (!outputFile.is_open())
    {
        throw std::runtime_error("Error opening file for writing: " + filePathName);
    }
    std::vector<Points> &points = triangulation.uniquePoints();
    std::vector<Triangle> &triangles = triangulation.triangles();

    outputFile << "o Cube" << std::endl;
    for (const Points &points : points)
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
