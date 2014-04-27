#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int main() {
    try {
        //int *a = new double(2);
        //throw new bad_cast("bad cast");
    } catch (const exception &e) {
        cout << "bad_cast" << endl;
        cout << e.what() << endl; 
    }

    try {
        int *a = new int[2446546546465464646548];
    } catch (const exception &e) {
        cout << "bad_alloc" << endl;
        cout << e.what() << endl; 
    }

    try {
        vector<int> a(1,1);
        a[2];
    } catch (const exception &e) {
        cout << "range_error" << endl;
        cout << e.what() << endl; 
    }

    try {
        vector<int> a;
        a.pop_back();
    } catch (const exception &e) {
        cout << "underflow_error" << endl;
        cout << e.what() << endl; 
    }

    try {
        throw new overflow_error("overflow");
    } catch (const exception &e) {
        cout << "overflow_error" << endl;
        cout << e.what() << endl; 
    }

    try {
        throw new domain_error("domain");
    } catch (const exception &e) {
        cout << "domain error" << endl;
        cout << e.what() << endl; 
    }

    try {
        throw new invalid_argument("invalid");
    } catch (const exception &e) {
        cout << "invalid argument" << endl;
        cout << e.what() << endl; 
    }

    try {
        throw new out_of_range("out of range");
    } catch (const exception &e) {
        cout << "out of range" << endl;
        cout << e.what() << endl; 
    }

    try {
        throw new length_error("length error");
    } catch (const exception &e) {
        cout << "length error" << endl;
        cout << e.what() << endl; 
    }

    return 0;
}
