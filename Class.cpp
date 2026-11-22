#include "FileManager.h"
#include <iostream>

void ClassifyFiles(const std::vector<SaveFileinfo> &file)
{
    for (const auto& entry : file)
    {
        if (entry.type != "File")
        {
            continue;
        }
        std::string ext = std::filesystem::path(entry.name).extension().string();
        if (ext == ".cpp" || ext == ".h"||ext==".main")
        {
            std::cout << entry.name << "->" << "code file" << std::endl;
        }
        else if (ext == ".txt")
        {
            std::cout << entry.name << "->" << "txt file" << std::endl;
        }
        else if (ext == ".png")
        {
            std::cout << entry.name << "->" << "png file" << std::endl;
        }
        else
        {
            std::cout << entry.name << "->" << "other file" << std::endl;
        }
    }
}
