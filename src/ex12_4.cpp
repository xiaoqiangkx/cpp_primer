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

int main() {
    double *num = new double(2.0);
    ifstream ifs("test.txt", ifstream::in);
    Test t("hello", 5, num, ifs);
    delete num;
    return 0;
}
