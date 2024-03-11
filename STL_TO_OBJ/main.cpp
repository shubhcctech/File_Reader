#include <iostream>
#include"headers/STLToOBJ_Reader.h"
#include"headers/STLToOBJ_Writer.h"

int main(){
            STLToOBJ_Reader fileReader;
            Triangulations triangulation = fileReader.stlReader("resources\\cube.stl");
            STLToOBJ_Writer filewriter;
            filewriter.stlObjWrite("output\\output.obj",triangulation); 
}