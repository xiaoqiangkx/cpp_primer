#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

template <typename T>
ostream& writeVal(ostream& out, const T& val) {
    out << val;
    return out;
}

int main(int argc, char* argv[]) {
    ofstream ofile("test.data");
    string s = "";
    stringstream ss(s);
    
    writeVal(cout, 1) << endl;
    writeVal(cout, 2.2) << endl;
    writeVal(ofile, "hello") << endl;
    writeVal(ss, "test");
    cout << "s=" << ss.str() << endl;
    ofile.close();
    return 0;
}
