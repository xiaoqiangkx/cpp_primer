#include <iostream>
#include <string>
#include "test1.cpp"
using namespace std;

class Person {
    public:
        typedef string str;
        Person(const string &_name, const string &_address): name(_name), address(_address) {}
        string get_name() const;
        string get_address() const;
        Person& plus(const string &add_str);
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

Person& Person::plus(const string &add_str) {
    name += add_str;
    return *this;
}

int main() {
    const string &data = "hello";
    string name("qingfeng");
    string address("Beijing");
    Person person(name, address);
    person.plus(address).plus(name).plus("hello");
    Person::str _name = person.get_name();
    cout << _name << endl << person.get_address() << endl;
    return 0;
}
