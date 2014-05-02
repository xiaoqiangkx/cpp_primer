#include <iostream>
#include <string>
using namespace std;

class NoName {
public:    
    NoName(): pstring(new string()), i(0), d(0) {
    }

    NoName(const NoName& nn): i(nn.i), d(nn.d), pstring(new string(*(nn.pstring))) {
        string s("123");
        *(nn.pstring) += s;
       
    }

    ~NoName() {if (pstring) delete pstring;}

    void set(string &s) {
        *pstring = s;
    }

    void change(NoName &nn) {
        string s("123");
        *(nn.pstring) += s;
    }

    string& get() {
        return *pstring;
    }
private:
    string *pstring;
    int i;
    double d;

};

int main() {
    string s("hello");
    NoName n1;
    n1.set(s);

    NoName n2(n1);
    string data = n2.get();
    cout << "data= " <<  data << endl;
    
    cout << "change n1" << n1.get() << endl;
    n2.change(n1);
    cout << "change n1" << n1.get() << endl;
    return 0;
}
