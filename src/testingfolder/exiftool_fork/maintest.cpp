#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

std::string getDateTimeOriginal(const std::string& filePath) 
{
    std::string command = "exiftool.exe -DateTimeOriginal -s -s -s \"" + filePath + "\"";
    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe) {
        throw std::runtime_error("Error running ExifTool command.");
    }

    char buffer[128];
    std::string result = "";
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL) 
        {
            result += buffer;
        }
    }
    _pclose(pipe);

    // Trim whitespace from result
    result.erase(result.find_last_not_of(" \n\r\t") + 1);

    return result;
}

std::vector<std::string> getFileList(const char* dirname) 
{
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;
    std::vector<std::string> fileList;

    // Construct the search path
    std::string searchPath = std::string(dirname) + "\\*.rw2";

    // Find the first file in the directory
    hFind = FindFirstFile(searchPath.c_str(), &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            // Check if the found entity is a file
            if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) 
            {
                std::string filename = findFileData.cFileName;
                std::string filePath = std::string(dirname) + "\\" + filename;
                fileList.push_back(filePath);
            }
        } while (FindNextFile(hFind, &findFileData) != 0);

        // Close the handle when finished
        FindClose(hFind);
    }
    else 
    {
        std::cerr << "Error opening directory " << dirname << ": " << GetLastError() << std::endl;
    }

    return fileList;
}

int main() 
{
    const char* dirname = "your_directory_path_here";
    std::vector<std::string> fileList = getFileList(dirname);

    for (const std::string& filePath : fileList) 
    {
        try 
        {
            std::string dateTimeOriginal = getDateTimeOriginal(filePath);
            std::cout << "File: " << filePath << ", Date Taken: " << dateTimeOriginal << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error processing file " << filePath << ": " << e.what() << std::endl;
        }
    }

    return 0;
}
