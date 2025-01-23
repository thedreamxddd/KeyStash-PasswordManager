#ifndef DISCOVERFILE_H
#define DISCOVERFILE_H
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

class discoverFile {
private:
    string line;
public:
    void geDiscoverFile(const fs::path& filePath) {
        ifstream file(filePath);
        while (getline(file, line)) {
        }
    }
};
#endif