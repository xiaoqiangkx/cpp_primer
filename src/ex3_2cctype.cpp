#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char* argv[]) {
    string s("data!!hello.");

    string::size_type punc_num = 0;

    for (string::size_type i = 0; i < s.size(); ) {
        // if we delete punction, we shouldn't make i plus one.
        if (ispunct(s[i])) {
            ++punc_num;
            s.erase(i, 1);
            
        } else {
            i++;
        }
    }

    cout << "the number of punction in " << s << " is " << punc_num << endl;
    return 0;
}
