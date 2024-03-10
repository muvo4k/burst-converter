# BO-Bracketing Organizer:

Sorts your bracketing and burst shots by timestamps into folders

## Status

1. Contains simple function which list all directories & files (also subdirectories with subsequent files without git) aswell count function which counts all files it encounters
2. Program chooses directory based on the directory during execution:
    2.1 Conditional within the program checks if user is the right input directory
        if not: program exits ; if yes: program resumes

        - Other possibilities: 
            - based on stdin 
            - same approach but if anwser is no change use a two created functions for choosing & changing to the right input directory maybe based on selection

3. Program uses the std::cin.fail() function with boolean which continues while the boolean is false
    cin.fail() returns true if the last cin command failed

## Next Steps

Done:
- decided that filecount is a seperate function even if this means repetitive code for readability

Upcoming:
- change the main file to cpp file handling stays in c for now
- ask for the input location

- fill array of string
- sort by filetypes

### Key characteristic of bracketing & burst shots

- continous naming with numbers
- date & timestamp
    - standalone as well as in combination with pattern of repeating iso or shutter values 
    - a fixed amount of burst shots, panasonic shots
#### problem which can occur a their key characteristic

Problem 1:
- false taken picture by pressing the shutter to short in between to soon
Solution 2: 
- timestamp checking
- seperation of too short shots
- preselection modus of input material: burst modus, bracketing modus 
## Project Timeline
1. Create Basic C Program which  **check headings** and **copies files** to new **create Folder**(yymmdd-bc-sorted)created by the first file and timestamp(exif data) which has each a NestedFolder() in it with.

1.a Common Problem to overcome with this program is to check how many pictures in a row where taken and sort them and create a overview with a txt file

2. Let program dynamically allocate more arrays to seperate the shorter file a list them also in the overview

3. Create GUI
4. Create Webamssembly Version

- create new directory archive
- moved makefile to new Location: archive
- created new Makefile to incooperate c++ and c files
- sketch a c outline to ask for user input(change to c++)
======