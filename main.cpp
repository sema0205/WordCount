#include <iostream>
#include <getopt.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>


int main (int argc, char *argv[]){

    // allOptions handles 0 parameters response
    bool allOptions = true;
    std::vector <std::string> filePaths;

    // cutOptions and fullOptions are used in getopt_long func which handles any console parameters
    const char* cutOptions = "lcwm";
    // no_argument helps using short parameters with fullname ones at one time in getopt_long func
    const struct option fullOptions[] = {
            { "lines", no_argument, NULL, 'l' },
            { "bytes", no_argument, NULL, 'c' },
            { "words", no_argument, NULL, 'w' },
            { "chars", no_argument, NULL, 'm' },
            { NULL, 0, NULL, 0 }
    };

    // code used to get getopt_long func response and compare console parameters to needed outputs
    int code;
    // indexOption is a pointer of current parameter variable from fullOption
    int indexOption;

    // get files paths
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            std::ifstream fileValidation;
            fileValidation.open(argv[i]);
            if (fileValidation.is_open()) {
                filePaths.push_back(argv[i]);
            } else {
                std::cout << "some errors in path of " << argv[i] << " file\n";
            }
        }
    }

    // check if there are no options
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            allOptions = 0;
            break;
        }
    }


    // implementation of getopt_long func
    while ((code = getopt_long(argc, argv, cutOptions, fullOptions, &indexOption)) != -1){

        switch(code) {
            // case 'l' handles -l --lines and all other possible console parameters (like -lcwm -mwl)
            case 'l': {
                int totalLines;
                for (auto file : filePaths) {
                    totalLines = 0;
                    std::ifstream readingFile(file);
                    totalLines = std::count(std::istreambuf_iterator<char>(readingFile), std::istreambuf_iterator<char>(), '\n');
                    std::cout << "There are " << totalLines + 1 << " lines " << "in " << file << " file\n";
                }
                break;
            }
            case 'c': {
                double totalBytes;
                for (auto file : filePaths) {
                    totalBytes = 0;
                    std::ifstream readingFile(file, std::ifstream::ate | std::ifstream::binary);
                    totalBytes = readingFile.tellg();
                    std::cout << "Total " << "size of file " << file << " is " << totalBytes << " bytes\n";
                }
                break;
            }
            case 'w': {
                std::size_t totalWords;
                std::ifstream readingFile;
                char ch;
                for (auto file : filePaths) {
                    totalWords = 1;
                    readingFile.open(file);
                    readingFile.get(ch);
                    while(ch != EOF) {
                        if (ch == ' ' || ch == '\n') {
                            totalWords += 1;
                        }
                        ch = readingFile.get();
                    }
                    std::cout << "There are " << totalWords << " words " << "in " << file << " file\n";
                }
                break;
            }
            case 'm': {
                std::size_t totalLetters;
                std::ifstream readingFile;
                char ch;
                for (auto file : filePaths) {
                    totalLetters = 0;
                    readingFile.open(file);
                    ch = readingFile.get();
                    while(ch != EOF) {
                        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                            totalLetters += 1;
                        }
                        ch = readingFile.get();
                    }
                std::cout << "There are " << totalLetters << " letters " << "in " << file << " file\n";

                }
                break;
            }
            // when we got a parameter like -a (which we don't know about)
            case '?': default: {
                printf("unknown option\n");
                break;
            }
        }
    }


    // handles case when there are no specified parameters in console
    if (allOptions) {
        int totalLines;
        double totalBytes;

        std::size_t totalWords;
        std::ifstream readingFile;
        char ch;

        std::size_t totalLetters;
        std::ifstream readingFile1;
        char ch1;

        for (auto file : filePaths) {
            totalLines = 0;
            std::ifstream readingFile(file);
            totalLines = std::count(std::istreambuf_iterator<char>(readingFile), std::istreambuf_iterator<char>(), '\n');
            std::cout << "There are " << totalLines + 1 << " lines " << "in " << file << " file\n";
        }

        for (auto file : filePaths) {
            totalBytes = 0;
            std::ifstream readingFile(file, std::ifstream::ate | std::ifstream::binary);
            totalBytes = readingFile.tellg();
            std::cout << "Total " << "size of file " << file << " is " << totalBytes << " bytes\n";
        }

        for (auto file : filePaths) {
            totalWords = 1;
            readingFile.open(file);
            readingFile.get(ch);
            while(ch != EOF) {
                if (ch == ' ' || ch == '\n') {
                    totalWords += 1;
                }
                ch = readingFile.get();
            }
            std::cout << "There are " << totalWords << " words " << "in " << file << " file\n";
        }

        for (auto file : filePaths) {
            totalLetters = 0;
            readingFile1.open(file);
            ch1 = readingFile1.get();
            while(ch1 != EOF) {
                if ((ch1 >= 'a' && ch1 <= 'z') || (ch1 >= 'A' && ch1 <= 'Z')) {
                    totalLetters += 1;
                }
                ch1 = readingFile1.get();
            }
            std::cout << "There are " << totalLetters << " letters " << "in " << file << " file\n";
        }
    }

    return 0;
}
