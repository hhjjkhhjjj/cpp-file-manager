#include "FileManager.h"

void ScanDirectory(const std::filesystem::path& path,std::vector<SaveFileinfo>& files)
{
    for(const auto& entry : std::filesystem::directory_iterator(path))
    {
        SaveFileinfo info;
        info.name=entry.path().filename().string();//name
        info.fullPath=std::filesystem::absolute(entry.path()).string();//fullpath
        if(entry.is_regular_file())
        {
            info.size=entry.file_size();//size
            info.type="File";
        }
        else if(entry.is_directory())
        {
            info.type="Directory";
        }
        else
        {
            info.type="Other";
        }
        files.push_back(info);
    }
}