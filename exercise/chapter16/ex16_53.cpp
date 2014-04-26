#include <iostream>
#include <vector>
using namespace std;

template <typename T>
size_t count(const vector<T> &vec, const T &val) {
   size_t cnt = 0;
   for (int i=0; i<vec.size(); i++) {
       if (vec[i] == val) cnt++;
   }

   return cnt;
}

int main() {
    int a[] = {1,2,3,4,5,3, 2, 3};
    vector<int> vec(a, a + sizeof(a)/sizeof(int));

    vector<double> vec_d(10, 1.0);
    cout << "count double 10 : " << count(vec_d, 1.0) << endl;

    vector<char> vec_c(10, 'c');
    cout << "count char 10 : " << count(vec_c, 'c') << endl;

    int result = count(vec, 3);
    cout << "count: " << result << endl;
    return 0;
}
