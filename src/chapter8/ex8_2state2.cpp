#include <iostream>
#include <istream>
using namespace std;

istream& print(istream &data) {
    int a;

    while (cin >> a) {
        cout << a << endl;
    }

    data.clear();
    return data;
}

int main(int argc, char* argv[]) {
    print(cin);
    return 0;
}
