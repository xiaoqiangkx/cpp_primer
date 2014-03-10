#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

string& my_tolower(string &temp) {
    for(string::size_type i = 0; i < temp.size(); i++) {
        temp[i] = tolower(temp[i]);
    }

    return temp;
}

int main(int argc, char* argv[]) {
    string s;
    vector<string> vec;

    while (cin >> s) {
        vec.push_back(s);
    }

    vector<string>::size_type cnt = 0;

    while (cnt < vec.size()) {
        string temp = vec[cnt];
        cout << my_tolower(temp)<<"\t";  
        cnt++;

        if (cnt % 8 == 0) {
            cout << endl;
        }
    }
    return 0;
}
