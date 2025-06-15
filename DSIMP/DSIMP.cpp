
#include <iostream>
#include "clsDBlLinkedList.h"
#include "clsDynamicArray.h"
#include "clsQueueLine.h"


using namespace std;

void DBLinkedListCalls() {
	clsDBlLinkedList<int> clsList;
	clsList.InsertAtBeginning(5);
	clsList.InsertAtBeginning(96);
	clsList.InsertAtBeginning(12);
	clsList.InsertAtBeginning(87);
	clsList.DeleteFistNode();
	clsList.DeleteLastNode();
	clsList.InsertAtEnd(8);
	clsList.InsertAtEnd(456);
	//clsList.Clear();
	clsList.PrintList();
	clsList.Update(1, 500);
	clsList.PrintList();

	//clsList.Reverse2();
	//clsList.PrintList();
	//clsDBlLinkedList<int> ::Node* N;
	//N = clsList.GetNode(1);
	//cout << N->data;
	//cout << "\n" << clsList.Size() << endl;
	//cout << clsList.IsEmpty() << endl;
}
void QueueCalls() {};
void StackCalls() {};

void DynamicArrays() {
	clsDynamicArray<int> MyDyArr(3);
	MyDyArr.setItem(0, 96);
	MyDyArr.setItem(1, 12);
	MyDyArr.setItem(2, 67);
	//MyDyArr.Resize(8);
	//MyDyArr.Reverse();
	MyDyArr.print();
	cout << "\n\n";
	//MyDyArr.print();
	//MyDyArr.Clear();
	//MyDyArr.DeleteFirstItem();
	//MyDyArr.DeleteFirstItem();
	//MyDyArr.DeleteLastItem();
	MyDyArr.InsertAt(0, 54);
	//MyDyArr.DeleteFirstItem();

	MyDyArr.print();
}
void CheckBangram(string str);
int main()
{
	//clsQueueLine ob1("A0", 10);
	//ob1.IssueTicket();
	//ob1.IssueTicket();
	//ob1.IssueTicket();
	//ob1.IssueTicket();
	//ob1.IssueTicket();
	//ob1.PrintInfo();
	//cout << endl;
	//ob1.PrintTnfoTickets();
	//ob1.ServeClient();
	//ob1.PrintInfo();
	//ob1.IssueTicket();
	//ob1.PrintTnfoTickets();


	//stack<int> sck;
	//sck.top();
	CheckBangram("kjh");
}



void CheckBangram(string str) {
	int counter = 0;
	int counteUniqueCh;
	bool isBangram = true;
	for (int i = 97; i <= 122; i++) {
		counteUniqueCh = 0;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] <= 90)
				str[j] += 32;
			if (i == int(str[j])) {
				counter++;
				counteUniqueCh++;
			}
		}
		if (counteUniqueCh > 1) {
			isBangram = false;
			break;
		}
		if (counter > 26) {
			isBangram = false;
			break;
		}
	}
	if (counter == 26 && isBangram)
		cout << "Bangram \n";
	else
		cout << "Not Bangram \n";
}








