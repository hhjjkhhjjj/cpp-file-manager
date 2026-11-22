#include "FileManager.h"
#include <iostream>

void copy(const std::vector<SaveFileinfo>& file,const std::string& input,const std::string& newpath)
{
    bool found = false;
    for (const auto& entry : file)
    {
        if (input == entry.name && entry.type == "File")
        {
            found = true;
            try
            {
                std::filesystem::copy_file(entry.fullPath, newpath);
                std::cout << "Copy success!" << std::endl;
                WriteLog("Copy",entry.fullPath,newpath);
            }
            catch (const std::filesystem::filesystem_error& e)
            {
                std::cout << "Copy failed: " << e.what() << std::endl;
            }

            break;
        }
    }
    if (found != true)
    {
        std::cout << "NO,no this file" << std::endl;
    }
}
