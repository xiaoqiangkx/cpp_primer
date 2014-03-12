#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(int argc, char* argv[]) {
    vector<double> vec(2, 2.2);
    double sum = accumulate(vec.begin(), vec.end(), 0);
    cout << sum << endl;
    return 0;
}
