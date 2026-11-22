#include "FileManager.h"
#include <iostream>

void ProcessDirectory(const std::filesystem::path& path,std::vector<SaveFileinfo>& files)
{
     try
    {
        if(std::filesystem::exists(path))//file exist
        {
            std::cout<<"OK,it exists"<<std::endl;
                if(std::filesystem::is_directory(path))//directory
                {
                    std::cout<<"this is address:"<<std::endl;
                        ScanDirectory(path,files);
                        ShowFiles(files);
                }
                else
                    {
                        std::cout<<"No!It not directory address"<<std::endl;
                    }
        }
        else
        {
            std::cout<<"NO,address is not"<<std::endl;
        }
    }
    catch(const std::filesystem::filesystem_error &e)
    {
        std::cerr<<"Error: "<<e.what()<<std::endl;
    }
}