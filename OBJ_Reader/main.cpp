#include <iostream>
#include"headers/OBJ_Reader.h"
#include"headers/OBJ_Writer.h"


int main(){
            OBJ_Reader fileReader;
            Triangulations triangulation = fileReader.objReader("resources\\cubeInput.obj");
            OBJ_Writer filewriter;
            filewriter.objWrite("output\\output.txt",triangulation); 
}