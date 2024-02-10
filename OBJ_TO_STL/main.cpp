#include "headers/OBJToSTL_Reader.h"
#include "headers/OBJToSTL_Writer.h"
#include <iostream>

int main()
{
    OBJToSTL_Reader fileReader;
    Triangulations triangulation = fileReader.objReader("resources\\cubeInput.obj");
    OBJToSTL_Writer filewriter;
    filewriter.objToStl("output\\outputSTL.stl", triangulation);
}