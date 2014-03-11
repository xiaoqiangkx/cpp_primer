#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    string line, word;
    ifstream ifile("test.data");

    while (getline(ifile, line)) {
        stringstream strm(line);
        while (strm >> word) {
            cout << word << endl;
        }
    }

    ifile.close();
    return 0;
}
