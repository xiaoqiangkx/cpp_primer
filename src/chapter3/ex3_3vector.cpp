#include <iostream>
#include <cassert>
#include <vector>
using namespace std;


int main(int argc, char* argv[]) {
    vector<int> vec;
    
    cout << "input the number you want to input" << endl;

    int num = 0;
    cin >> num;
    assert (num > 0);

    cout << "input your " << num << " numbers" << endl;

    for (vector<int>::size_type i=0; i != num; i++) {
       int temp = 0;
       cin >> temp;
       vec.push_back(temp); 
    }

    vector<int>::size_type i = 0;
    for (i=0; i < vec.size()-1; i+=2) {
            cout << vec[i] + vec[i+1] << " ";
    }

    if (vec.size() % 2 != 0) {
        cout << vec[vec.size()-1];
    }
    cout << endl;

    
    vector<int>::size_type first = 0, last = 0;
    for (first = 0, last = vec.size()-1; first < last; first++, last--) {
        cout << vec[first] + vec[last] << " "; 
    }

    if (first == last) {
        cout << vec[first];
    }
    cout << endl;

    return 0;
}
