#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class GT_cls {
    public:
        GT_cls(size_t val = 0) : bound(val) {}
        bool operator()(const string& s) { return s.size() >= bound; }
    private:
        size_t bound;
};

int main(int argc, char* argv[]) {
    string data[] = {"123", "234533", "43523"};
    vector<string> v(data, data+3);

    size_t s1 = count_if(v.begin(), v.end(), GT_cls());
    size_t s2 = count_if(v.begin(), v.end(), GT_cls(3));
    size_t s3 = count_if(v.begin(), v.end(), GT_cls(4));

    cout << s1 << " " << s2 << " " << s3 << endl;
    return 0;
}
