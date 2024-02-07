#include "headers/FileReader.h"
#include "headers/FileWriter.h"
#include<iostream>

int main() {

    std::cout<<"***********************************************"<<std::endl;
    std::cout<<"Enter Conversion for files"<<std::endl
    <<"1) .stl To .txt"<<std::endl
    <<"2) .obj To .txt"<<std::endl
    <<"3) .obj To .stl"<<std::endl
    <<"4) .stl To .obj"<<std::endl;

    std::cout<<"***********************************************"<<std::endl;

    int choice;
    std::cin>>choice;
    switch(choice){
        case 1: {
            FileReader fileReader;
            Triangulations triangulation = fileReader.stlReader("stl_files\\cube.stl");
            FileWriter filewriter;
            filewriter.stlWrite("text_files\\outputSTL.txt",triangulation); 
            break;
        }
        case 2:{
            FileReader fileReader;
            Triangulations triangulation = fileReader.objReader("obj_files\\cubeInput.obj");
            FileWriter filewriter;
            filewriter.objWrite("text_files\\outputOBJ.txt",triangulation); 
            break;
        }
        case 3:{
            FileReader fileReader;
            Triangulations triangulation = fileReader.objReader("obj_files\\cubeInput.obj");
            FileWriter fileWriter;
            fileWriter.objToStl("stl_files/objToStl.stl",triangulation);
        }
        case 4:{
            FileReader fileReader;
            Triangulations triangulation = fileReader.stlReader("stl_files\\cube.stl");
            FileWriter fileWriter;
            fileWriter.stlToObj("obj_files/stlToObj.obj",triangulation);
        }
    }


    
    return 0;
}
