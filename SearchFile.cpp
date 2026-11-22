#include "FileManager.h"
#include <iostream>

void SearchFile(const std::vector<SaveFileinfo> &file, const std::string &targetName)
{
    bool found = false;
    if (targetName != "")
    {
        for (const auto &entry : file)
        {
            if (entry.name.find(targetName) != std::string::npos)
            {
                found = true;
                std::cout << "Found: " << entry.name << std::endl;
                std::cout << "FullPath: " << entry.fullPath << std::endl;
            }
        }
        if (!found)
        {
            std::cout << "NO!It is not here!!!" << std::endl;
        }
    }
    else
    {
        std::cout << "NO input!!!" << std::endl;
    }
}