#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<string, string> workList;
    workList.insert(make_pair("a", "123"));
    workList.insert(make_pair("b", "123"));
    workList.insert(make_pair("a", "456"));

    multimap<string, string>::iterator it;
    if ( (it = workList.find("a")) != workList.end())
            workList.erase("a");

    if ( (it = workList.find("c")) != workList.end())
            workList.erase("c");

    for (it = workList.begin(); it != workList.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }
    return 0;
}
