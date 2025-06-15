
#include <iostream>
#include<vector>
using namespace std;


void userInput(vector<int>& nums) {
    int n;
    char r = 'y';
    while (r == 'y') {
        cout << "Enter A Number ";
        cin >> n;
        nums.push_back(n);
        cout << "Do You Want to Enter Anohter Number ";
        cin >> r;
    }
}

void PrintNums(vector<int> nums) {
    for (auto& e : nums) {
        cout << e << " ";
    }
}





struct Employee {
    string FirstName;
    string LastName;
    double Salary;
};

void ReadEmpData(vector<Employee>& empsData) {
    char ans = 'y';
    Employee emp;
    while (ans == 'y') {
        cout << "Enter Employee Data \n";
        cin >> emp.FirstName;
        cin >> emp.LastName;
        cin >> emp.Salary;
        empsData.push_back(emp);
        cout << "Do You Want to Enter Antoher Employee y/n ";
        cin >> ans;
    }
}
void PrintEmpsData(vector<Employee> empsData) {
    for (Employee& i : empsData) {
        cout << i.FirstName << " ";
        cout << i.LastName << " ";
        cout << i.Salary << " ";
        cout << endl;
    }
}


int main()
{


    vector<string> names{ "Fady", "Ahmed", "Hosam" };
    try {
        cout << names.at(3);
    }
    catch (...) {
        cout << "Something Went Wrong Please ";
    }
    vector<string>::iterator it;
    for (it = names.begin(); it != names.end(); it++) {
        //cout << *it << " ";
    }








    int a = 10;
    int& y = a;
    //cout << &a << "           " << &y;


    vector<Employee> empsData;
    //ReadEmpData(empsData);
    //PrintEmpsData(empsData);

    vector<Employee> emps = {
        {"Fady", "Esam", 5000},
        {"Ramy", "Hamed", 4000},
        {"Hani", "Ramez", 3000},

    };
    for (Employee &i : emps) {
        //cout << i.FirstName << " ";
    }




    vector<int> nums;
    //userInput(nums);
    //PrintNums(nums);

    vector<int> vNumbers = {8, 1, 5, 9, 44};
    for (auto &n : vNumbers) {
        //cout << n << " ";
    }
}

