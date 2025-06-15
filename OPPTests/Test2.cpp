#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include "MyLib.h";
#include<iomanip>;
#include "Product.h";
using namespace std;



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
    __declspec(property(get = getFirstName, put = setFirstName)) string confFirstName;
};



void CalcDays() {
    int DayOrder = 0;
    int day; cin >> day;
    int month; cin >> month;
    for (int i = 1; i < month; i++) {
        if (i == 2) DayOrder += 28;
        else if(i == 8 || i % 2 == 1) DayOrder += 31;
        else DayOrder += 30;
    }
}



class clsCalculator {
private:
    int value = 0;
public:
    void Add(int v) {
        value += v;
    }
    void Subtract(int v) {
        value -= v;
    }
    void Multiply(int v) {
        value *= v;
    }
    void Clean() {
        value = 0;
    }
    void PrintResult() {
        cout << "Result is = " << value << endl; 
    }
};


void MyFunc() {
    static int n = 1;
    //cout << n << "\n";
    n++;
}

enum Color {Red, Blue, Green, Yellow};


struct stAddress {
    string StreetName;
    string BuildingNo;
    string ZipCode;
};

void InsertData(stAddress* st) {
    cin >> st->StreetName;
    cin >> st->BuildingNo;
    cin >> st->ZipCode;

}
void ShowData(stAddress st) {
    cout << st.StreetName << endl;
}

struct Person {
    string FirstName;
    string LastName;
    int age;
    string phone;
};

void ReadInfo(Person& ps) {
    ps.FirstName = "";
    ps.LastName = "";
    ps.age = 19;
    ps.phone = "5412.0.";
}


void FillPerson(Person ps[2]) {
    ReadInfo(ps[0]);
    ReadInfo(ps[0]);

}

void GetPerson(Person ps[2]) {
    for (int i = 0; i < 2; i++) {

    }
}

#include<ctime>;
#pragma warning(disable : 4996) 

enum Directions {North, South, East, West};

#include<ctime> // for rand and srand
#include<stdlib.h> // for time

string ReverseWords(string& s) {
    string res = "";
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        temp += s[i];
        if (i == s.length() - 1) {
            s[i] = ' ';
            temp += ' ';
        }
        if (s[i] == ' ') {
            res = temp + res;
            temp = "";
        }
    }
    res.pop_back();
    return res;
}

#include<vector>


void ReplaceWord(string& OriginalStr, string OldWord, string NewWord) {
    string result = "";
    string temp = "";
    for (int i = 0; i < OriginalStr.length(); i++) {
        if (OriginalStr[i] != ' ')
            temp += OriginalStr[i];
        if(OriginalStr[i] == ' ' || i == OriginalStr.length() - 1) {
            if (temp == OldWord) 
                result += NewWord;
            else
                result += temp;
            result += ' ';
            temp = "";
        }
    }
    OriginalStr = result;



}
vector<string> Split(string& s, char c) {
    vector<string> v;
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != c)
            temp += s[i];
        if (s[i] == c || i == s.length() - 1) {
            v.push_back(temp);
            temp = "";
        }
    }
    return v;
}

string join(vector<string> s, char c) {
    string result = "";
    for (string& i : s) {
        result += i + c;
    }
    result.pop_back();
    return result;
}

void PrintFirstLetterOfEachWord(string& s) {
    for (int i = 0; i < s.length(); i++) {
        if (i == 0) {
            cout << s[i] << endl;
        }
        else if (s[i] == ' ' && i != s.length() - 1) {
            cout << s[i + 1] << endl;
        }
    }
}

char InvertCharachter(char c) {
    return c >= 'a' && c <= 'z' ? c - 32 : c + 32;
}


void InvertString(string& s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') continue;
        result += InvertCharachter(s[i]);
    }
    s = result;
}


void UpperCase(string& s) {
    for (int i = 0; i < s.length(); i++) {
        if (i == 0) {
            s[i] -= 32;
        }
        else if (s[i] == ' ' && i != s.length() - 1) {
            s[i+1] -= 32;
        }
    }
}


void EncryptString(string& s, int EncryptKey) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = char(int(s[i]) + EncryptKey);
    }

}
#include<cmath>



void DecryptString(string& s, int EncryptKey) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = char(int(s[i]) - EncryptKey);
           
    }

}


void GenerateRand(char c) {
    int r;
    switch (c)
    {
    //case '^' || '*': r =  rand() % ()
    default:
        break;
    }
}

string GenerateWord() {
    string result = "";
    for (int i = 0, j = 0; i < 19; i++) {
        result += char(65 + rand() % (90 - 65 + 1));  
    }
    return result;
}


void FillArrayWithRandom(int size, int arr[], int arr2[], int sumArr[]) {
    for (int i = 0; i < size; i++) {
        arr[i] = 1 + rand() % (100 - 1 + 1);
        arr2[i] = 1 + rand() % (100 - 1 + 1);
        //cout << arr[i] << " " << arr2[i] << endl;
        cout << arr[i] << " ";
        sumArr[i] = arr[i] + arr2[i];
    }
    for (int i = 0; i < 5; i++) {
        //cout << sumArr[i] << " ";
    }
    cout << endl;
}



void ReversArray(int size, int arr[]) {
    int reversedArr[5];
    for (int i = 0; i < size; i++) {
        reversedArr[i] = arr[size - 1 - i];
        cout << reversedArr[i] << " ";
    }
}

int GetMaxNumberOfAnArray(int size, int arr[]) {
    int maxNum = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxNum) maxNum = arr[i];
    }
    return maxNum;
}

int GetMinNumberOfAnArray(int size, int arr[]) {
    int minNum = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minNum) minNum = arr[i];
    }
    return minNum;
}
// 5 2 9 12 0
//82 39 19 68 26
void GetMaxValueSecondMaxValue(int size, int arr[]) {
    int maxNum = 0;
    int secondMaxNum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > maxNum) {
            secondMaxNum = maxNum;
            maxNum = arr[i];
        }
        else if(arr[i] > secondMaxNum) {
            secondMaxNum = arr[i];
        }
    }
    cout << maxNum << " " << secondMaxNum << endl;
}

void GetMinValueSecondMinValue(int size, int arr[]) {
    int minNum = INT_MAX;
    int secondMinNum = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] < minNum) {
            secondMinNum = minNum;
            minNum = arr[i];
        }
        else if (arr[i] < secondMinNum) {
            secondMinNum = arr[i];
        }
    }
    cout << minNum << " " << secondMinNum << endl;
}


#include<functional>


void ABS(int& num) {
    num >= 0 ? num : num * -1;
}


// Fucntion Has Call Back in its Parameters

void testfnc(function<void(int)> f) {
    f(5);
}

void testfnc2(int (*calback)(double)) {

}


int main() {
    srand(time(0));
    

    int x = 10;
    int& y = x;

    cout << &y;



    int arr[5];
    int arr2[5];
    int sumArr[5];
    //FillArrayWithRandom(5, arr, arr2, sumArr);
    //GetMaxValueSecondMaxValue(5, arr);
    //cout << GetMaxNumberOfAnArray(5, arr) << endl << GetMinNumberOfAnArray(5, arr);
    //ReversArray(5, arr);
    //for (int i = 0; i < 5; i++) {
    //    cout << arr[i] << " ";
    //}

    cout << endl;
    //cout << GenerateWord();
    //string s = "Mohammed";
    //EncryptString(s, 2);
    // cout << s;
    //string s = "hello i am a programmer";
    //UpperCase(s);
    //PrintFirstLetterOfEachWord(s);
    //cout << s;
    //string s = "tyt,eitos,eotiudf,ieousdfj,ieuoih";
    //for (string &i : Split(s, ',')) {
    //    //cout << i << endl;
    //}
    //cout << join(Split(s, ','), ',');
    
    //srand(time(0));
    //int randNum = 1 +  rand() % (3 - 1 + 1);
    //string s = "Welcome to Egypt , Egypt Egypt";
    //ReplaceWord(s, "Egypt", "USkj;ljfdosajeionnfnmnmsdfnoewjA"); // Wrong
    //cout << s;
    //string s = "I Love Programming Languages Like C# and Python";

    
    //cout << ReverseWords(s);


    //cout << res;






    //string s = "Is for rtx";
    //string result = "";
    //for (int i = 0; i < s.length(); i++) {
    //    if (s[i] == ' ') 
    //        result += ' ';
    //    if(s[s.length() - 1 - i] != ' ')
    //        result += s[s.length() - 1 - i];
    //}
    //cout << result;



    //time_t t = time(0);
    //char* dt = ctime(&t);
    //tm* gmti = gmtime(&t);
    //dt = asctime(gmti);
    //cout << dt;

    //string s1 = "Welocme to you in Abou Hadhoud Course, He Teaches C++ Programming Language";

    //Person ps[2];

    //FillPerson(ps);
    //GetPerson(ps);
    //stAddress stData[2];
    //for (int i = 0; i < 2; i++) {
    //    cin >> stData[i].StreetName;
    //    cin >> stData[i].BuildingNo;
    //    cin >> stData[i].ZipCode;
    //}
    //for (int i = 0; i < 2; i++) {
    //    cout << stData[i].StreetName << endl;
    //    cout << stData[i].BuildingNo << endl;
    //    cout << stData[i].ZipCode << endl;
    //}


    //stAddress st;
    //InsertData(&st);
    //ShowData(st);
    //ShowData(st);
    //ShowData(st);

    Color c;
    c = Color::Red;
    Product myProduct(5, 199.99, "Laptop");
    //myProduct.displayData();
    //MyFunc();
    //MyFunc();
    //MyFunc();
    const double PI = 3.141592653589793;
    //printf("The Value Pi %.*f \n", 2, PI);
    //cout << fixed << setprecision(5);
    //printf("The number is %d \n", 5);
    //printf("The Formatted is %0*d \n", 4, 1);

    //MyLib::print();
    //int array[3] = { 82, 16, 29 };
    //for (int e : array) {
    //    cout << e << endl;
    //}
    //CalcDays();
    //clsPerson pers;
    //pers.confFirstName = "Fady";
    //cout << pers.confFirstName << endl;
    //clsCalculator clsC;
    //clsC.Add(10);
    //clsC.Subtract(3);
    //clsC.PrintResult();



    system("pause>0");
    return 0;
}
