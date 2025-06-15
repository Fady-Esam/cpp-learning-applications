

#include <iostream>
using namespace std;
struct Person {
	string Name;
	int age;
};

int main()
{
	int lenght = 3;
	int* PtrDynamic = new int[lenght];
	//PtrDynamic = new int[lenght];
	for (int i = 0; i < lenght; i++) {
		cin >> *(PtrDynamic + i);
	}
	for (int i = 0; i < lenght; i++) {
		cout << *(PtrDynamic + i) << " ";
	}
	delete[] PtrDynamic;


	int* ptrY;
	ptrY = new int;
	*ptrY = 12;
	//cout << ptrY;
	delete ptrY;

	void* PtrGen;
	float x = 10.5;
	PtrGen = &x;
	//cout << PtrGen << endl;
	//cout << *(static_cast<float*>(PtrGen));



	Person Ps, * ptrPs;
	Ps.Name = "Fady";
	Ps.age = 19;
	ptrPs = &Ps;


	//cout << ptrPs->Name << "     " << ptrPs->age;

	int arr[] = { 5, 1, 82, 65, 34 };
	int* ptr = arr;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		//cout << &arr[i] << endl;
	}
	//cout << endl << endl;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		//cout << ptr + i << endl;
	}

	//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
	//	cout << *(ptr + i) << endl;
	//}


	//int x = 10;
	//int* ptr = &x;
	//x = 8;
	//cout << *ptr;
}

