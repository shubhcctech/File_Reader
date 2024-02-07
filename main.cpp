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
            Triangulations triangulation = fileReader.stlReader("resources\\cube.stl");
            FileWriter filewriter;
            filewriter.stlWrite("output\\outputSTL.txt",triangulation); 
            break;
        }
        case 2:{
            FileReader fileReader;
            Triangulations triangulation = fileReader.objReader("resources\\cubeInput.obj");
            FileWriter filewriter;
            filewriter.objWrite("output\\outputOBJ.txt",triangulation); 
            break;
        }
        case 3:{
            FileReader fileReader;
            Triangulations triangulation = fileReader.objReader("resources\\cubeInput.obj");
            FileWriter fileWriter;
            fileWriter.objToStl("output\\objToStl.stl",triangulation);
        }
        case 4:{
            FileReader fileReader;
            Triangulations triangulation = fileReader.stlReader("resources\\cube.stl");
            FileWriter fileWriter;
            fileWriter.stlToObj("output\\stlToObj.obj",triangulation);
        }
    }


    
    return 0;
}
