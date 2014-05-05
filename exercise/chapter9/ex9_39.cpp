#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(T st, T ed) {
    while (st != ed) {
        cout << *st << " ";
        st++;
    }

    cout << endl;
}

int main() {
    string delims = ", :";

    string test = "abc : dfa, dfad dfad dfewe dfad k, : dfad, dfad";
    vector<string> svec;

    string::size_type st = 0, ed=0;
    while ( (st = test.find_first_not_of(delims, st)) != string::npos) {
        ed = test.find_first_of(delims, st+1);
        svec.push_back(string(test, st, ed - st));

        if (ed == string::npos) {
            break;
        }

        st = ed + 1;
    }

    cout << "raw: " << test << endl;
    cout << "length of data=" << svec.size() << endl;

    print(svec.begin(), svec.end());
    
    int index = 0;
    
    for (int i=1; i<svec.size(); i++) {
        if (svec[i].size() > svec[index].size()) {
          index = i;  
        }
    }

    cout << "the longest string is " << svec[index] << endl;

    return 0;
}
