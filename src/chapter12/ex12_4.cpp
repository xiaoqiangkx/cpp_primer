#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Test {
    public:
        Test(const string _data, int _val, double *_num, ifstream& _ifs):data(_data), val(_val), num(_num), ifs(_ifs) {}
    private:
        const string data;
        int val;
        double *num;
        ifstream &ifs;
};

class Nodefault {
    public:
        explicit Nodefault(int _val): val(_val) {}
        bool compare(Nodefault t) { return t.get_val() == val; }
        int get_val() { return val;}
    private:
        int val;
};

int main() {
    double *num = new double(2.0);
    ifstream ifs("test.txt", ifstream::in);
    Test t("hello", 5, num, ifs);
    delete num;

    Nodefault n1(5);
    cout << "result=" << n1.compare(Nodefault(5)) << endl;
    return 0;
}
