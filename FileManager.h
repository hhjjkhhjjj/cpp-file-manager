#pragma once

#include <string>
#include <cstdint>
#include <vector>
#include <fstream>
#include <filesystem>

struct SaveFileinfo
{
    std::string name;
    std::string type;
    std::uintmax_t size=0;
    std::string fullPath;
};
void ShowFiles(const std::vector<SaveFileinfo>& files);
void ScanDirectory(const std::filesystem::path& path,std::vector<SaveFileinfo>& files);
void ProcessDirectory(const std::filesystem::path& path,std::vector<SaveFileinfo>& files);
void SearchFile(const std::vector<SaveFileinfo>& file,const std::string& targetName);
void ClassifyFiles(const std::vector<SaveFileinfo>& file);
void copy(const std::vector<SaveFileinfo>& file,const std::string& input,const std::string& newpath);
void MoveFile(const std::vector<SaveFileinfo>& file, const std::string& input, const std::filesystem::path& destination);
void WriteLog(const std::string& operation, const std::filesystem::path& source, const std::filesystem::path& destination);
void ViewLogs();

