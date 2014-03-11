#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    vector<string> vec;
    vec.push_back("hello1");
    vec.push_back("hello2");

    ofstream ofile;

    typedef vector<string>::iterator it_type;
    it_type st = vec.begin(), ed = vec.end();
    while (st != ed) {
        ofile.open((*st).c_str());

        if (!ofile) {
            ofile.clear();
            continue;
        } else {
            ofile << (*st) << endl;
        }

        ofile.close();
        st++;
    }

    return 0;
}
