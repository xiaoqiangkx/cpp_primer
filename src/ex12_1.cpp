#include <iostream>
#include <string>
#include "test1.cpp"
#include "test2.cpp"
using namespace std;

class Person {
    public:
        typedef string str;
        Person(const string &_name, const string &_address): name(_name), address(_address) {}
        string get_name() const;
        string get_address() const;
    private:
        str name;
        string address;
}; 

string Person::get_name() const {
    return name;
}

string Person::get_address() const {
    return address;
}

int main() {
    string name("qingfeng");
    string address("Beijing");
    Person person(name, address);
    Person::str _name = person.get_name();
    cout << _name << endl << person.get_address() << endl;
    return 0;
}
