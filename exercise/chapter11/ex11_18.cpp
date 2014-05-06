#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iterator>
using namespace std;

struct IS_ODD {
    bool operator()(int val) {
        return val % 2 != 0;
    }
};

int main() {

    ofstream ofs1("test11_18_1.dat");
    ofstream ofs2("test11_18_2.dat");

    istream_iterator<int> input(cin);
    istream_iterator<int> end_of_stream;
    ostream_iterator<int> output1(ofs1, " ");
    ostream_iterator<int> output2(ofs2, " ");

    vector<int> ivec(input, end_of_stream);
    vector<int>::iterator mid = partition(ivec.begin(), ivec.end(), IS_ODD());

    copy(ivec.begin(), mid, output1); 
    copy(mid, ivec.end(), output2); 

    return 0;
}
