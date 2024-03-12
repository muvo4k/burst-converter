#include <windows.h>
#include <iostream>
#include "globals.h"

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