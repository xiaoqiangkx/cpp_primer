#include <iostream>
#include <string>
using namespace std;

class Person {
    public:
        Person(string _name, string _address): name(_name), address(_address) {}
        string get_name();
        string get_address();
    private:
        string name;
        string address;
}; 

string Person::get_name() {
    return name;
}

string Person::get_address() {
    return address;
}

int main() {
    string name("qingfeng");
    string address("Beijing");
    Person person(name, address);
    cout << person.get_name() << endl << person.get_address() << endl;
    return 0;
}
