// CPP Libraries
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <limits> // for numeric_limits
#include <ios>    // for streamsize

#include "globals.h"
#include "functions.h"

int main(void)
{
    // Storage
    std::string answer;
    bool valid = false;

    while (!valid) 
    {
        std::cout << "Are you in the right directory? ";
        std::cout << "Please answer with yes or no: ";
        std::getline(std::cin, answer);

        if (std::cin.fail()) 
        {
            std::cout << "Error reading input. Please try again." << std::endl;
        }
        else if (answer != "yes" && answer != "no") 
        {
            std::cout << "Invalid input. Please answer with yes or no." << std::endl;
        }
        else if (answer == "yes" || answer == "no")
        {
            valid = true;
        }
    }

    if (answer == "no") 
    {
        std::cout << "Program will terminate here! Please change to data path first and then run the program again." << std::endl;
        return EXIT_SUCCESS;
    }

    // MAIN LOGIC HERE
    

    // Listing Filesname & Directory(subdirectories & its files included)
    /*
    listFilesWin(".");
    countFilesWin(".");
    listFilesUnix(".");
    countFilesUnix(".");
    */


    const char* dirname = "."; // your_directory_path_here "directory_path"
    std::vector<std::string> filenames;
    std::vector<HANDLE> filePointers;
    std::vector<FILETIME> timestamps;

    filePointers = getFilePointers(dirname, filenames, timestamps);

    // Now you have an array of file pointers, an array of filenames, and an array of timestamps
    // You can use these to read binary data from each file and access their timestamps

    // Don't forget to close the file handles when you're done with them

    // TEST PRINT

    std::cout << "Filename Vector elements: ";
    for (int i = 0; i < filenames.size(); ++i) {
        std::cout << filenames[i] << ", ";
    }
    std::cout << std::endl;

    for (HANDLE hFile : filePointers) 
    {
        CloseHandle(hFile);
    }



    // check filecount
    printf("Total files in directory: %d\n", filecount);


    // Create an Array of Strings
/*     char *filenames[filecount]; */
    // Count Filecount 


    return 0;
}
