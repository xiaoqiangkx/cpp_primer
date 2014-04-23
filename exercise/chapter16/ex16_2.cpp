#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

/* 流没有引用?? */
template <typename T1, typename T2>
T1& s_write(T1 &out, T2 val) {
    out << val;
}

int main() {

    double dval = 0.88;
    double fval = -12.3;
    string oristr = "this is a test", desstr;

    ofstream ofs("test.data");
    
    ostringstream oss(desstr);

    cout << "write data to cout " << endl;
    s_write(cout, 1) << endl;
    s_write(cout, dval) << endl;
    s_write(cout, fval) << endl;
    s_write(cout, oristr) << endl;

    cout << "write data to fstream " << endl;
    s_write(ofs, 1) << endl;
    s_write(ofs, dval) << endl;
    s_write(ofs, fval) << endl;
    s_write(ofs, oristr) << endl;

    cout << "write data to stringstream " << endl;
    s_write(oss, 1) << endl;
    s_write(oss, dval) << endl;
    s_write(oss, fval) << endl;
    s_write(oss, oristr) << endl;
    cout << "sstream is " << oss.str() << endl;

    ofs.close();
    return 0;
}
