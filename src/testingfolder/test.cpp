#include <iostream>
#include <string.h>

#include <limits>
#include <ios>

int main(void)
{
    std::string answer;

    // check for valid input
    bool valid = false;
    // std::getline(std::cin, answer);
    while (!valid || answer != "yes")
    {
        if (std::cin.fail())
        {
            std::cout << "Error reading input. Please try again." << std::endl;
            // Clear the input buffer and reset error flags
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, answer);
        }
        if (answer != "yes" && answer != "no")
        {
            std::cout << "Invalid input. Please answer with yes or no: ";
             // Clear the input buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, answer);
        }
        if (answer == "no")
        {
            std::cout << "Program will terminate here! Please change to data path first and then run the program again" << std::endl;
            return EXIT_SUCCESS;
        }
        if (answer == "yes")
        {
            valid = true;
        }
    }
}