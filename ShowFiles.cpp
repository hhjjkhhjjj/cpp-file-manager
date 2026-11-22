#include "FileManager.h"
#include <iostream>

void ShowFiles(const std::vector<SaveFileinfo>& files)
{
    for(const auto& info : files)
    {
        std::cout<<"Name: "<<info.name<<std::endl;
        std::cout<<"Type: "<<info.type<<std::endl;
        std::cout<<"fullpath: "<<info.fullPath<<std::endl;
        if(info.type=="File")
        {
            std::cout<<"Size: "<<info.size<<"bytes"<<std::endl;
        }
        else
        {
            std::cout<<"Size: --" <<"bytes"<<std::endl;
        }
    }
}