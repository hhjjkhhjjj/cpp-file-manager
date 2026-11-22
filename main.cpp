#include <iostream>
#include <string>
#include <limits>
#include <filesystem>
#include <vector>
#include <cstdint>
#include "FileManager.h"

// namespace fs = std::filesystem;

int main()
{

    std::vector<SaveFileinfo> files;
    std::string input, newpath;
    int num = -1;

    while (num != 0)
    {
        std::cout << "========== FILE MANAGER ==========" << std::endl;
        std::cout << std::endl;

        std::cout << "1. Scan Directory" << std::endl;
        std::cout << "2. Show Files" << std::endl;
        std::cout << "3. Search File" << std::endl;
        std::cout << "4. Classify Files" << std::endl;
        std::cout << "5. Copy File" << std::endl;
        std::cout << "6. Move / Rename File" << std::endl;
        std::cout << "7. View Operation Logs" << std::endl;
        std::cout << "0. Exit" << std::endl;

        std::cout << std::endl;
        std::cout << "Please enter your choice:" << std::endl;

        while (true)
        {
            if (!(std::cin >> num))
            {
                if (std::cin.eof())
                {
                    return 0;
                }

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Input error, try again: ";
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            break;
        }

        switch (num)
        {
            case 0:
                break;
            case 1:
            {
                std::cout << "=====Path input=====" << std::endl;
                std::cout << "Please put your address in it " << std::endl;
                std::getline(std::cin, input);
                if (!std::filesystem::is_directory(input))
                {
                    std::cout << "NOT this address.Please try to input again!!";
                    break;
                }
                files.clear();
                std::filesystem::path path(input);
                ProcessDirectory(path, files);
                break;
            }
            case 2:
            {
                ShowFiles(files);
                break;
            }
            case 3:
            {
                std::cout << "=====Search function=====" << std::endl;
                std::cout << "Please put your search file in it" << std::endl;
                std::getline(std::cin, input);
                SearchFile(files, input);
                break;
            }
            case 4:
            {
                std::cout << "=====Class=====" << std::endl;
                ClassifyFiles(files);
                break;
            }
            case 5:
            {
                std::cout << "=====copy path function=====" << std::endl;
                std::cout << "Please input your want to filename" << std::endl;
                std::getline(std::cin, input);
                std::cout << "Please input your newfullpath" << std::endl;
                std::getline(std::cin, newpath);
                copy(files, input, newpath);
                break;
            }
            case 6:
            {
                std::cout << "=====Move path function=====" << std::endl;
                std::cout << "Please input your want to filename" << std::endl;
                std::getline(std::cin, input);
                std::cout << "Please input your newfullpath" << std::endl;
                std::getline(std::cin, newpath);
                MoveFile(files, input, newpath);
                break;
            }
            case 7:
            {
                ViewLogs();
                break;
            }
            default:
            {
                std::cout << "Invalid choice! " << std::endl;
                break;
            }
        }
    }
}
