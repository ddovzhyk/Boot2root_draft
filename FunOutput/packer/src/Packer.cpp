#include <iostream>
#include <dirent.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <map>

std::map<int, std::string> filesContentMap;

const std::string FUN_PATH("ft_fun");

bool readFile(const std::string &path)
{
    std::ifstream inputFile(path);
    std::string line;
    std::string fileContentBuffer;
    unsigned int mapIndex = 0;

    if (!inputFile) {
        std::cerr << "ERROR: Cannot open file!" << std::endl;
        return false;
    }

    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }
        
        fileContentBuffer += line + "\n";

        const std::string::size_type fileWordIndex = line.find("file");
        if (fileWordIndex != std::string::npos) {
            unsigned int numberIndex = static_cast<unsigned int>(fileWordIndex);
            numberIndex += 4;

            std::cout << "DEBUG LOG: line with file number before:" << line << std::endl;
            line.erase(0, numberIndex);
            std::cout << "DEBUG LOG: line with file number after:" << line << std::endl;
            mapIndex = std::stoi(line);
        }

    }

    filesContentMap[mapIndex] = fileContentBuffer;

    return true;
}

int parseDirectory(const std::string &path)
{
    DIR *directory = opendir(path.c_str());
    struct dirent *fileStructure;

    if (directory == NULL) {
        /* could not open directory */
        perror ("");
        std::cerr<<"ERROR: ";
        return EXIT_FAILURE;
    }

    std::cout << "List of files:" << std::endl;

    /* print all the files and directories within directory */
    while ( (fileStructure = readdir(directory)) != NULL ) {
        if (strcmp(fileStructure->d_name, ".") == 0 ||
                strcmp(fileStructure->d_name, "..") == 0) {
            continue;
        }
        std::cout << fileStructure->d_name << std::endl;
        std::string filePath(path + "/" + std::string(fileStructure->d_name));
        readFile(filePath);
    }

    closedir (directory);
    return 0;
}

bool createFinalFile()
{
    std::map<int, std::string>::iterator it;
    std::ofstream outputFile("../Output.cpp");

    if (!outputFile) {
        std::cerr << "ERROR: Cannot open file!" << std::endl;
        return false;
    }

    for ( it = filesContentMap.begin(); it != filesContentMap.end(); ++it ) {
        outputFile << it->second;
    }

    outputFile.close();
}

int main()
{
    try {
        if (parseDirectory(FUN_PATH) == EXIT_FAILURE) {
            return EXIT_FAILURE;
        }

        if (!createFinalFile()) {
            return EXIT_FAILURE;
        }
    } catch (...) {
        std::cerr << "ERROR: Uknown error!" << std::endl;
        return false;
    }

    return 0;
}
