#include <iostream>
#include <stdexcept>
using namespace std;

istream& getData(istream &is) {

    int num;

    try {
    while (is >> num, !is.eof()) {
        if (is.bad()) {
            throw std::runtime_error("IO stream corrupted.");
        }

        if (is.fail()) {
//            cerr << "bad:" << is.bad() << ",fail:" << is.fail() << ",eof:" << is.eof() << endl;
            cerr << "bad data, try again." << endl;
            is.clear(); 
            is.ignore(200, ' '); 
            //cerr << "bad:" << is.bad() << ",fail:" << is.fail() << ",eof:" << is.eof() << endl;
            continue;
        }

        cout << num << endl;
    }
    } catch (const std::runtime_error& e) {
        cerr << "IO Exception." << endl;
    }


    is.clear();
    return is;
}

int main() {

    istream& is2 = getData(cin);

//    getData(is2);

    return 0;
}
