#include <iostream>
using namespace std;

namespace Exercise {
    int ival = 0;
    double dval = 0;
    const int limit = 1000;
};

int ival = 0;
// using Exercise::ival;
// using Exercise::dval;
// using Exercise::limit;

using namespace Exercise;

void manip() {
//   using namespace Exercise;

   // using Exercise::ival;
   // using Exercise::dval;      
   // using Exercise::limit;
    double dvar = 3.1416;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
}

int main() {
    return 0;
}
