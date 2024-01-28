#include <stdio.h>
#include <dirent.h>

#include "globals.h"
#include "functions.h"

int main(void)
{
    // Listing Filesname & Directory(subdirectories & its files included)
    listFiles(".");

    // make sure that it is a raw-file -> (other files)



    // check filecount
    printf("Total files in directory: %d\n", countFiles(".", &filecount));


    // Create an Array of Strings
/*     char *filenames[filecount]; */
    // Count Filecount 


    return 0;
}