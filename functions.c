#include <stdio.h>
#include <string.h>
#include <dirent.h>

void listFiles(const char* dirname)
{
     DIR *directory = opendir(dirname); // dot means see all files/directory in current directory

    if (directory == NULL)
    {
        return;
    }

    struct dirent *entity;
    entity = readdir(directory); //Each call to readdir(directory) reads the next directory entry and returns a pointer to it.So, the first call outside the loop reads the first entry
    while (entity != NULL)
    {
        printf("%hhd %s/%s\n", entity->d_type, dirname,entity->d_name);
        if (entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) // conditional comparing . and .. so that there i no indefinetly looping between directories
        {
            char path[100] = { 0 };
            strcat(path, dirname);
            strcat(path, "/" );
            strcat(path, entity->d_name);
            listFiles(path);
        }
        entity = readdir(directory);
    }

    closedir(directory);
}