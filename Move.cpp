#include <iostream>
#include "FileManager.h"

void MoveFile(const std::vector<SaveFileinfo>& file, const std::string& input, const std::filesystem::path& destination)
{
        bool found = false;
    for (const auto& entry : file)
    {
        if (input == entry.name && entry.type == "File")
        {
            found = true;
            try
            {
                if (std::filesystem::exists(destination))
                {
                    std::cout << "Destination already exists" << std::endl;
                    return;
                }
                std::filesystem::rename(entry.fullPath, destination);
                std::cout << "Move success!" << std::endl;
                WriteLog("Move", entry.fullPath, destination);
            }
            catch (const std::filesystem::filesystem_error& e)
            {
                std::cout << "Move failed: " << e.what() << std::endl;
            }

            break;
        }
    }
    if (found != true)
    {
        std::cout << "NO,no this file" << std::endl;
    }

}
