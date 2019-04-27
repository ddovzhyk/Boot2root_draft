#include <dirent.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

std::map<int, string> filesContentMap;

bool readFile(const std::string &path)
{
    std::ifstream inputFile(path);
    std::string line;
    std::string bufferForContent;

    if (!inputFile) {
        std::cerr << "ERROR: Cannot open file!" << std::endl;
        return false;
    }
    try {
    	int index_i = 0;
        while (std::getline(inputFile, line)) {
            if (line.empty()) {
                continue;
            }
        
        	bufferForContent += line;

        	if (line.find("file") != std::string::npos) {
        		int indexOfNumber = line.find("file");
        		index += 4;
        		
        		std::cout << 

        		filesContentMap[]
        	}

		}

    } catch (...) {
        std::cerr << "ERROR: Uknown error!" << std::endl;
        return false;
    }

    return true;
}

int main()
{
	DIR *dir = opendir ("./ft_fun");
	struct dirent *ent;
	if (dir == NULL) {
		/* could not open directory */
	  	perror ("");
 	 	return EXIT_FAILURE;
 	 } else {
 	 	/* print all the files and directories within directory */
	  	while ((ent = readdir (dir)) != NULL) {
	  		if (strcmp(strent->d_name, ".") == 0 || 
	  			strcmp(strent->d_name, "..") == 0) {
	  			continue;
	  		}

			std::cout << "List of files:" << std::endl;
	    	std::cout << ent->d_name << std::endl;


	  	}

	  	closedir (dir);
	}
}