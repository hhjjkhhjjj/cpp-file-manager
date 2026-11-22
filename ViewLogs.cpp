#include "FileManager.h"
#include <iostream>

void ViewLogs()
{
    std::ifstream log("operations.log");

    std::string line;

    while (std::getline(log, line))
    {
        std::cout << line << std::endl;
    }
}
