// CPP Libraries
#include <iostream>
#include <string>

#include <limits> // for numeric_limits
#include <ios>    // for streamsize


#include "globals.h"
#include "functions.h"

int main(void)
{
    // Storage
    std::string answer;

    // Ask the User for File Location
    std::cout << "Are you in the Directory were the File is stored. Anwser with 'yes or no': ";
    
    // check for valid input
    bool valid = false;

    while (!valid) 
    {
        std::cout << "Please answer with yes or no: ";
        std::getline(std::cin, answer);

        if (std::cin.fail()) {
            std::cout << "Error reading input. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (answer != "yes" && answer != "no") {
            std::cout << "Invalid input. Please answer with yes or no." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else 
        {
            valid = true;
        }
    }

    if (answer == "no") 
    {
        std::cout << "Program will terminate here! Please change to data path first and then run the program again." << std::endl;
        return EXIT_SUCCESS;
    }

    // Program executes here !!!
    

    // Listing Filesname & Directory(subdirectories & its files included)
    listFilesWin(".");
    countFilesWin(".");
    // make sure that it is a raw-file -> (other files)



    // check filecount
    printf("Total files in directory: %d\n", filecount);


    // Create an Array of Strings
/*     char *filenames[filecount]; */
    // Count Filecount 


    return 0;
}
