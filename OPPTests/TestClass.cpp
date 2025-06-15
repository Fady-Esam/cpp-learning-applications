#include "TestClass.h"
#include<iostream>
using namespace std;


TestClass::Car::Car(int t, float r, string f) : t(t), r(r), f(f) {}
void TestClass::Car::display() {
	cout << "Hello I am in diplay \n";
}


