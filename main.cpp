// CPP Libraries
#include <iostream>
#include <string>
// C Libraries
#include <stdio.h>
#include <dirent.h>

#include <limits> // for numeric_limits
#include <ios>    // for streamsize


#include "globals.h"
#include "functions.h"

int main(void)
{
    // Storage
    std::string answer;

    // Ask the User for File Location
    std::cout << "Are you in the Directory were the File is stored. Anwser with 'Yes or No': ";
    std::getline(std::cin, answer);
    
    // check for valid input <-------------------- incooperate the cin.fail() function & also correct the functionallity
    bool valid = false;

    // while (std::cin.fail() || (answer != "yes" && answer != "no")) 
    // {
    //     if (std::cin.fail()) 
    //     {
    //         std::cout << "Error reading input. Please try again." << std::endl;
    //         // Clear the input buffer and reset error flags
    //         std::cin.clear();
    //         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //     } 
    //     else 
    //     {
    //         std::cout << "Invalid input. Please answer with yes or no: ";
    //         // Clear the input buffer
    //         std::cin.clear();
    //         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //     }

    //     std::getline(std::cin, answer);

    //     if (answer == "no") 
    //     {
    //         std::cout << "Program will terminate here! Please change to data path first and then run the program again" << std::endl;
    //         return EXIT_SUCCESS;
    //     }
    // }

    // Discard the newline character from the input buffer
    std::getline(std::cin, answer);

    while (answer != "yes" && answer != "no") {
        std::cout << "Invalid input. Please answer with yes or no: ";
        std::getline(std::cin, answer); // Read input

        if (answer == "no") {
            std::cout << "Program will terminate here! Please change to data path first and then run the program again" << std::endl;
            return EXIT_SUCCESS;
        }
    }
    
    // Program executes here !!!
    

    // Listing Filesname & Directory(subdirectories & its files included)
    listFiles(".");
    countFiles(".");
    // make sure that it is a raw-file -> (other files)



    // check filecount
    printf("Total files in directory: %d\n", filecount);


    // Create an Array of Strings
/*     char *filenames[filecount]; */
    // Count Filecount 


    return 0;
}