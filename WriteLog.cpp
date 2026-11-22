#include "FileManager.h"
#include <fstream>
#include <iostream>

void WriteLog(const std::string& operation, const std::filesystem::path& source, const std::filesystem::path& destination)
{
    std::ofstream log("operations.log", std::ios::app);
    if (!log)
    {
        std::cerr << "Failed to open log file!" << std::endl;
        return;
    }
    log << operation << ": " << source.string() << "->" << destination.string() << std::endl;
}
