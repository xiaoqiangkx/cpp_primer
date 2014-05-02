#include <iostream>
using namespace std;

class Person {
    public:
        Person(const string& _name, const string &_addr):
            name(_name), addr(_addr) {}
        
        const string& get_name() const {
            return name;
        }

        string get_addr() const {
            return addr;
        }
    private:
        string name;
        string addr;
};

int main() {
    const Person p("person", "Beijing");
    cout << p.get_addr() << " " << p.get_name() << endl;
    return 0;
}
