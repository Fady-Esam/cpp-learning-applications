

#include <iostream>
#include <string>
using namespace std;

//
//class Person {
//protected:
//    string name;
//    int age;
//
//public:
//    Person(string n, int a) : name(n), age(a) {}
//
//    void displayInfo() {
//        cout << "Name: " << name << ", Age: " << age << endl;
//    }
//};


class clsPerson {
    string firstName;
    string secondName;
public:
    void setFirstName(string n) {
        firstName = n;
    }
    string getFirstName() {
        return firstName;
    }
};


int main()
{
    //string s = "Is Do itr";
    //string result = "";
    //for (int i = 0; i < s.length(); i++) {
    //    result[i] = s[s.length() - 1 - i];
    //}
    //cout << result;

    
    //Person p("Fady", 20);
    //p.displayInfo();
    clsPerson pers;
    pers.setFirstName("Fady");
    //cout << pers.getFirstName();


    system("pause>0");
    return 0;
}

