
#include <iostream>
using namespace std;


class Car {
public:
	int val;
	static int counter;
	Car() {
		counter++;
	}
	static int Func1() {
		return 10;
	}
	int Func2() {
		return 81;
	}
	void Print() {
		cout << val << endl;
		cout << counter << endl;
	}
};
int Car::counter = 0;


class Person{
private:
	int _ID;
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	Person(int ID, string FirstName, string LastName, string Email, string Phone) {
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;

	}
	int GetID() {
		return _ID;
	}
	void SetFirstName(string FirstName) {
		_FirstName = FirstName;
	}
	string GetFirstName() {
		return _FirstName;
	}
	void SetLastName(string LastName) {
		_LastName = LastName;
	}
	string GetLastName() {
		return _LastName;
	}
	void SetEmail(string Email) {
		_Email = Email;
	}
	string GetEmail() {
		return _Email;
	}
	void SetPhone(string Phone) {
		_Phone = Phone;
	}
	string GetPhone() {
		return _Phone;
	}
	void Print() {
		cout << "ID " << _ID << endl;
		cout << "First Name " << _FirstName << endl;
		cout << "Last Name " << _LastName << endl;
		cout << "Email " << _Email << endl;
		cout << "Phone " << _Phone << endl;
	}
	void SendTextMessage(string body) {
		cout << "To " << _Email << " => " << body << endl;
	}
	void SendSMS(string body) {
		cout << "To " << _Phone << " => " << body << endl;
	}
};

class Employee : public Person {
private:
	string _Title;
	string _Department;
	double _Salary;
public:
	Employee(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, double Salary)
		:Person(ID, FirstName, LastName, Email, Phone) {
		_Title = Title;
		_Department = Department;
		_Salary = Salary;
	}
	void SetTitle(string Title) {
		_Title = Title;
	}
	string GetTitle() {
		return _Title;
	}
	void SetDepartment(string Department) {
		_Department = Department;
	}
	string GetDepartment() {
		return _Department;
	}
	void SetSalary(double Salary) {
		_Salary = Salary;
	}
	double GetSalary() {
		return _Salary;
	}
	void Print() {
		Person::Print();
		cout << "Title " << _Title << endl;
		cout << "Department " << _Department << endl;
		cout << "Salary " << _Salary << endl;

	}
};



class Developer : public Employee {
private:
	string _ProgrammingLanguage;
public:
	Developer(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, double Salary, string ProgrammingLanguage)
		:Employee(ID, FirstName, LastName, Email, Phone, Title, Department, Salary){
			_ProgrammingLanguage = ProgrammingLanguage;
		}

	void SetProgrammingLanguage(string ProgrammingLanguage) {
		_ProgrammingLanguage = ProgrammingLanguage;
	}
	string GetProgrammingLanguage() {
		return _ProgrammingLanguage;
	}
	void Print() {
		Employee::Print();
		cout << "ProgrammingLanguage " << _ProgrammingLanguage << endl;
	}
};




class A {
private:
	int val1;
	int Func1() { return 1; }
protected:
	int val2;
	int Func2() { return 2; }
public:
	int val3;
	int Func3() { return 3; }
};


class B : protected A {

};
class C : public B {

};


class clsBase {
public:
	string Name = "Fady";
	virtual void Print() {
		cout << "I am in Base \n";
	}
	virtual void Test() {
		cout << "Test ";
	}
};


class clsDerived : public clsBase {
public:
	string Title = "Software Engineer";
	void Print() override {
		cout << "I am in Derived \n";
	}
};


// Interface
class Mobile {
	virtual void Dial(string num) = 0;
	virtual void SendSMS(string phone, string text) = 0;
	virtual void TakePictur() = 0;

};




class IPhone : public Mobile {
public:
	void Dial(string num) {

	}
	void SendSMS(string phone, string text)  {

	}
	void TakePictur() {

	}
};




class clsA {
private:
	int _Val1;
protected:
	int Val3;
public:
	int Val2;
	clsA() {
		_Val1 = 10;
		Val2 = 20;
		Val3 = 30;
	}

	friend class clsB;


	template<typename T>
	T Swap(T x, T y) {
		T temp = x;
		x = y;
		y = temp;
		return temp;
	}




};





class clsB {
public:
	void Print(clsA AObj) {
		cout << AObj.Val2 << endl;
	}
};




class A1 {
private:
	int _Val1;
protected:
	int Val3;
public:
	int Val2;
	A1() {
		_Val1 = 10;
		Val2 = 20;
		Val3 = 30;
	}

	friend int Sum(A1 A1Obj);
};




int Sum(A1 A1Obj) {
	return A1Obj._Val1 + A1Obj.Val2 + A1Obj.Val3;
}





class InclClass {
	class InnClass {
	public:
		int _x;
		string _n;
		double _s;
	public:
		InnClass(int x, string n, double s) {
			_x = x;
			_n = n;
			_s = s;
		}
	};
public:
	string _data;
	InnClass InnObj;
public:
	InclClass(string data, int x, string n, double s): InnObj(x, n, s) {}

};


class TestOp {
private:
	int x;
	int y;
public:
	TestOp(int vx, int vy) : x(vx), y(vy) {}
	TestOp operator + (TestOp to) {
		TestOp temp(1, 5);
		temp.x = x + to.x;
		temp.y = y + to.y;
		return temp;
	}


	//void operator +(int y) {
	//	x += y;
	//}
	void Print() {
		cout << x;
	}
};



class Count {
private:
	int value = 0;
public:
	Count(int v = 0): value(v) {}
	Count operator + (const Count c) {
		Count CountObj;
		CountObj.value = value + c.value;
		return CountObj;
	}
	Count RetCount() {
		return Count();
	}
	void Print() {
		cout << value;
	}
};

class Point {
private:
	int x, y;

public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	bool operator==(const Point other) {
		return (x == other.x && y == other.y);
	}
	bool operator!=(const Point other) {
		return !(x == other.x && y == other.y);
	}

};

#include<map>
#include <functional> 



void TestCall(function<void(int)> c) {
	c(5);
}


void calc(int) {
}


void TestCall2(void (*f)(int) ) {

}



int main()
{
	
	TestCall2(calc);
	clsA cs;
	//cout << cs.Swap<int>(8, 65);
	Count count1(3);
	Count count2(8);
	Count count3(6);
	Count Result = count1 + count2 + count3;



	
	map<int, int> data = 
	{
		{1, 5},
		{2, 98},
		{1, 5},
	};
	cout << data[2] << endl;










	//Result.Print();
	
	//TestOp to(5, 6);
	// TestOp to3 = to + to;
	//to.Print();
	//InclClass obj("", 10, "Fady", 5000);
	//A1 A1Obj;
	//cout << Sum(A1Obj);
	//clsA AObj;
	//clsB Bobj;
	//Bobj.Print(AObj);





	//IPhone IPh;
	
	//clsDerived cD;
	//Static-Early Binding
	// At Compile Time
	//cD.Print();
	//cout << cD.Title << endl;
	// UpCasting
	//clsBase* clsDConv = &cD;
	// Late-Dynamic Binding
	// At Run Time
	//clsDConv->Print();
	//cout << clsDConv->Name << endl;


	//Developer d(1, "Fady", "Esam", "Fady@gmail.com", "06549841", "Software Engineer", "Development", 5000, "C++");
	//d.Print();

	//Employee employee1(1, "Fady", "Esam", "Fady@gmail.com", "06549841", "Software Engineer", "Development", 5000);
	//employee1.Print();
	//cout << employee1.GetDepartment() << endl;
	//Person p(1, "Fady", "Esam", "Fady@gmail.com", "06549841");
	//p.Print();
	//p.SendTextMessage("Hello");
	//Car c1, c2, c3;
	//cout << Car::Func1() << endl;

 //c1.val = 45;
	//c2.val = 931;
	//c3.val = 78;
	//c1.Print();
	//c2.Print();
	//c3.Print();
	system("pause>0");
	return 0;
}

