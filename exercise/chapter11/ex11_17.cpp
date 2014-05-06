#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

int main() {

    istream_iterator<int> input(cin);
    istream_iterator<int> end_of_stream;
    ostream_iterator<int> output(cout, " ");

    vector<int> ivec(input, end_of_stream);
    sort(ivec.begin(), ivec.end());

    unique_copy(ivec.begin(), ivec.end(), output);
    return 0;
}
