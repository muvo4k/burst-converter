// Windows Shell Functions 
/*
void listFilesWin(const char* dirname);
void countFilesWin(const char* dirname);
*/
std::vector<HANDLE> getFilePointers(const char* dirname, std::vector<std::string>& filenames, std::vector<FILETIME>& timestamps);
// Unix Terminal Functions
/*
void countFilesUnix(const char* dirname);
void listFilesUnix(const char* dirname);
*/
// Functions for checking the OS

