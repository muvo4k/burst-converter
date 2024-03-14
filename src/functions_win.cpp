#include <windows.h>
#include <iostream>
#include "globals.h"
#include <vector>

void countFilesWin(const char* dirname) 
{
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;

    // Construct the search path
    std::string searchPath = std::string(dirname) + "\\*";

    // Find the first file in the directory
    hFind = FindFirstFile(searchPath.c_str(), &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            // Check if the found entity is a file
            if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                filecount++;
            }
        } while (FindNextFile(hFind, &findFileData) != 0);

        // Close the handle when finished
        FindClose(hFind);
    }
    else {
        std::cerr << "Error opening directory " << dirname << ": " << GetLastError() << std::endl;
    }
}

void listFilesWin(const char* dirname) 
{
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;

    // Construct the search path
    std::string searchPath = std::string(dirname) + "\\*";

    // Find the first file in the directory
    hFind = FindFirstFile(searchPath.c_str(), &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            // Exclude current directory (".") and parent directory ("..")
            if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
                // Print the type and name of the entity
                std::cout << ((findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ? "D " : "F ") << dirname << "\\" << findFileData.cFileName << std::endl;

                // If it's a directory, recursively list its contents
                if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                    std::string newPath = std::string(dirname) + "\\" + findFileData.cFileName;
                    listFilesWin(newPath.c_str());
                }
            }
        } while (FindNextFile(hFind, &findFileData) != 0);

        // Close the handle when finished
        FindClose(hFind);
    }
    else 
    {
        std::cerr << "Error opening directory " << dirname << ": " << GetLastError() << std::endl;
    }
}

std::vector<HANDLE> getFilePointers(const char* dirname, std::vector<std::string>& filenames, std::vector<FILETIME>& timestamps) 
{
    // https://learn.microsoft.com/de-de/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataa
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;
    std::vector<HANDLE> filePointers;

    // Construct the search path
    std::string searchPath = std::string(dirname) + "\\*";

    // Find the first file in the directory
    hFind = FindFirstFile(searchPath.c_str(), &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) 
    {
        do 
        {
            // Check if the found entity is a file: https://learn.microsoft.com/de-de/windows/win32/fileio/file-attribute-constants
            if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) 
            {
                std::string filename = findFileData.cFileName;
                std::string filePath = std::string(dirname) + "\\" + filename;
                HANDLE hFile = CreateFile(filePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
                if (hFile != INVALID_HANDLE_VALUE) {
                    filePointers.push_back(hFile);
                    filenames.push_back(filename);
                    timestamps.push_back(findFileData.ftLastWriteTime);
                }
                else 
                {
                    std::cerr << "Error opening file " << filename << ": " << GetLastError() << std::endl;
                }
            }
        } while (FindNextFile(hFind, &findFileData) != 0);

        // Close the handle when finished
        FindClose(hFind);
    }
    else 
    {
        std::cerr << "Error opening directory " << dirname << ": " << GetLastError() << std::endl;
    }

    return filePointers;
}