

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void insertAtBegining(Node* &n, int dat) {
	Node* newNode = new Node();
	newNode->data = dat;
	newNode->next = n;
	n = newNode;
}


void insertEnd(Node* &head, int dat) {
	Node* newNode = new Node();
	newNode->data = dat;
	newNode->next = NULL;
	if (head == NULL) {
		head = newNode;
	}
	else {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;  
	}
}

void insertAfter(int dat, Node* InsAft) {
	Node* newNode = new Node();
	newNode->data = dat;
	newNode->next = InsAft->next;
	InsAft->next = newNode;
}


Node* FindNode(Node* head, int dat) {
	Node* temp = head;
	while (temp != NULL) {
		if (temp->data == dat) {
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}



void DeleteNode(Node* &head, int dat) {
	Node* CurrentNode = head;
	Node* NodeBefore = NULL;
	if (head == NULL) return;
	if (head->data == dat) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	while (CurrentNode != NULL) {
		if (CurrentNode->data == dat) {
			NodeBefore->next = CurrentNode->next;
			delete CurrentNode;
			return;
		}
		else {
			NodeBefore = CurrentNode;
		}
		CurrentNode = CurrentNode->next;
	}
}

void DeleteFirstNode(Node* &head) {
	if (head != NULL) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void DeleteLastNode(Node*& head) {
	Node* LastNode = head;
	Node* PreviousLastNode = head;
	if (head == NULL) return;
	if (head->next == NULL) {
		head = NULL;
		delete LastNode;
		delete PreviousLastNode;
		return;
	}
	while (LastNode->next != NULL) {
		PreviousLastNode = LastNode;
		LastNode = LastNode->next;
	}
	PreviousLastNode->next = NULL;
	delete LastNode;
}
















void printList(Node* Head) {
	// Node* temp = Head;
	while (Head != NULL) {
		cout << Head->data << endl;
		Head = Head->next;
	}
}


#include<map>

int main()
{


#pragma region Map

	map<string, int> grades
	{
		{"Fady", 15},
		{"Hamed", 62},
		{"Ramy", 98},

	};


	for (const auto &i : grades) {
		cout << i.first << endl;
	}

#pragma endregion












	Node* Head = NULL;
	//insertAtBegining(Head, 5);
	//insertAtBegining(Head, 12);
	//insertAtBegining(Head, 78);
	//insertAtBegining(Head, 49);
	//insertAtBegining(Head, 67);

	insertEnd(Head, 5);
	insertEnd(Head, 12);
	insertEnd(Head, 78);
	insertEnd(Head, 49);
	DeleteNode(Head, 12);
	insertEnd(Head, 67);
	DeleteFirstNode(Head);

	//printList(Head);

	//Node* n1 = new Node();
	//Node* n2 = new Node();
	//Node* n3 = new Node();

	//n1->data = 58;
	//n2->data = 76;
	//n3->data = 29;

	//n1->next = n2;
	//n2->next = n3;
	//n3->next = NULL;

	//Node* Head = n1;
	//while (Head != NULL) {
	//	cout << Head->data << endl;
	//	Head = Head->next;
	//}















#pragma region Queue

	queue<int> values;
	values.push(15);
	values.push(49);
	values.push(74);
	values.push(63);
	while (!values.empty()) {
		//cout << values.front() << endl;
		values.pop();
	}



#pragma endregion



#pragma region Stack
	stack<int> nums;
	nums.push(5);
	nums.push(12);
	nums.push(98);
	nums.push(41);
	nums.push(74);

	while (!nums.empty()) {
		//cout << nums.top() << endl;
		nums.pop();
	}

#pragma endregion




#pragma region Matrix
	int matrix[][3] = {{4, 6, 8}, {32, 96, 19}};
	for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++) {
		for (int j = 0; j < 3; j++) {
			//cout << matrix[i][j] << " ";
		}
		// cout << endl;
	}
#pragma endregion



	system("pause>0");
	return 0;
}

