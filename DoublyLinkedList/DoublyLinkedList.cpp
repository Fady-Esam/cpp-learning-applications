

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
};
void InsertAtBeginnig(Node* &head, int dat) {
	Node* newNode = new Node();
	newNode->data = dat;
	newNode->prev = NULL;
	newNode->next = head;
	if(head != NULL)
		head->prev = newNode;
	head = newNode;
}

Node* FindNode(Node*& head, int dat) {
	Node* CurrentNode = head;
	while (CurrentNode != NULL) {
		if (CurrentNode->data == dat) {
			return CurrentNode;
		}
		CurrentNode = CurrentNode->next;
	}
	return NULL;
}

void InsertAfter(Node* nd, int dat) {
	Node* newNode = new Node();
	newNode->data = dat;
	newNode->prev = nd;
	newNode->next = nd->next;
	nd->next->prev = newNode;
	nd->next = newNode;
}

void InsertAtEnd(Node*& head, int dat) {

	Node* LastNode = head;
	Node* newNode = new Node();
	newNode->data = dat;
	newNode->next = NULL;
	if (head == NULL) {
		newNode->prev = NULL;
		head = newNode;
	}
	else {
		while (LastNode->next != NULL) {
			LastNode = LastNode->next;
		}
		LastNode->next = newNode;
		newNode->prev = LastNode;

	}
}


void DeleteNode(Node*& head, Node* NodeToDelete) {
	if (head == NULL || NodeToDelete == NULL) return;
	if (head == NodeToDelete) {
		head = NodeToDelete->next;
		head->prev = NULL;


		delete NodeToDelete;
		return;
	}
	NodeToDelete->next->prev = NodeToDelete->prev;
	NodeToDelete->prev->next = NodeToDelete->next;
	
	delete NodeToDelete;
}



void DeleteFirstNode(Node*& head) {
	if (head == NULL) return;
	Node* FirstNode = head;
	head = FirstNode->next;
	head->prev = NULL;
	delete FirstNode;
}


void DeleteLastNode(Node*& head) {
	if (head == NULL) return;
	Node* LastNode = head;
	while (LastNode->next != NULL) {
		LastNode = LastNode->next;
	}
	if (LastNode->prev != NULL) {
		LastNode->prev->next = NULL;
	}
	else
		head = NULL;
		delete LastNode;

}



void PrintList(Node* head) {
	Node* CurrentNode = head;
	while (CurrentNode != NULL) {
		cout << CurrentNode->data << endl;
		CurrentNode = CurrentNode->next;
	}
}

int main()
{
	Node* Head = NULL;
	//InsertAtBeginnig(Head, 12);
	//InsertAtBeginnig(Head, 96);
	//InsertAtBeginnig(Head, 47);
	InsertAtEnd(Head, 12);
	InsertAtEnd(Head, 96);
	InsertAtEnd(Head, 47);
	DeleteLastNode(Head);
	DeleteLastNode(Head);
	DeleteLastNode(Head);

	PrintList(Head);
}
