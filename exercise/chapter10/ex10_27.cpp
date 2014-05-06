#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<string, string> workList;
    workList.insert(make_pair("a", "123"));
    workList.insert(make_pair("b", "123"));
    workList.insert(make_pair("a", "456"));

    typedef multimap<string, string>::iterator map_it;
    pair<map_it, map_it> it = workList.equal_range("a");

    workList.erase(it.first, it.second);

    multimap<string, string>::iterator wit;
    for (wit = workList.begin(); wit != workList.end(); wit++) {
        cout << wit->first << " : " << wit->second << endl;
    }
    return 0;
}
