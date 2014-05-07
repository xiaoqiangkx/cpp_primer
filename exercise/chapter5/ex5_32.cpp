#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main() {
    int *p = new int(2);
   // char *c = static_cast<char*>(p);
    char *c = reinterpret_cast<char*>(p);
    return 0;
}
