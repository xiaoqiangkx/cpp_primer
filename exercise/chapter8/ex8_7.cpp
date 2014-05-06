#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main() {
    char* carr[] = {"ex8_1.txt", "ex8_3.txt", "ex8_2.txt"};
    vector<string> svec(carr, carr + sizeof(carr)/sizeof(char*));

    ifstream input;
    for (vector<string>::iterator st=svec.begin(); st!=svec.end(); st++) {
       input.open(st->c_str()); 

       if (!input) {
           cerr << "failed to open " << st->c_str() << endl;
       } else {
            cout << "suceess to open " << st->c_str() << endl;
       }

       input.close();
       input.clear();
    }
    return 0;
}
