#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

int main() {
    char* data[] = {"abc", "cda"};
    
    list<char*> li(data, data+2);
    vector<string> vec;
    vec.assign(li.begin(), li.end());
    
    cout << vec[0] << " " << vec[1] << endl;
    return 0;
}
