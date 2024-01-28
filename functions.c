#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h> // Include errno header for error handling

int countFiles(const char* dirname, int filecount)
{
    // Open a Directory
    DIR *directory = opendir(dirname);

    // Error Checking
    if (directory == NULL)
    {
        fprintf(stderr, "Error opening directory %s: %s:\n", dirname, strerror(errno));
    }

    // Creating struct pointer to interate over files
    struct dirent *entity;
    
    // While filepointer is not NULL 
    while ((entity = readdir(directory)) != NULL)
    {
        // If filepointer is a File
        if (entity->d_type == DT_REG)
        {
            filecount ++;
        }
    }
    //Close the filepointer
    closedir(directory);
    return filecount;
}

void listFiles(const char* dirname)
{
    DIR *directory = opendir(dirname); // dot means see all files/directory in current directory

    if (directory == NULL)
    {
        fprintf(stderr, "Error opening directory %s: %s\n", dirname, strerror(errno));
        return;
    }


    struct dirent *entity;
    // Call to readdir(directory) reads the next directory entry and returns a pointer to it.So, the first call outside the loop reads the first entry
    entity = readdir(directory);
    while (entity != NULL)
    {
        printf("%hhd %s/%s\n", entity->d_type, dirname,entity->d_name);
        if (entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, ".." ) != 0 && strcmp(entity->d_name, ".git") != 0) // conditional comparing . and .. so that there i no indefinetly looping between directories
        {
            char path[100] = { 0 };
            strcat(path, dirname);
            strcat(path, "/" );
            strcat(path, entity->d_name);
            listFiles(path);
        }
        entity = readdir(directory);
    }

    if (errno != 0)
    {
        fprintf(stderr, "Error reading directory %s: %s\n", dirname, strerror(errno)); // Print error message if readdir() fails
    }

    closedir(directory);
}