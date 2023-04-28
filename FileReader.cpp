#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

class FileReader
{

public:
    static vector<pair<string, double>> read(const char* fileName) {
        fstream newfile;
        vector<pair<string, double>> fileData;
        newfile.open(fileName, ios::in);
        if (newfile.is_open()) {
            string line;
            while (getline(newfile, line)) {
                size_t find = line.find("|");
                if (!line.empty() && find != string::npos) {
                    string name = line.substr(0, find);
                    double salary = stod(line.substr(find + 1));
                    fileData.push_back(make_pair(name, salary));
                }
            }
        }
        newfile.close();
        return fileData;
    }
};