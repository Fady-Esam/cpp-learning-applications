#pragma once
#include<iostream>
using namespace std;


template<class T>
class clsDBlLinkedList {
	int count = 0;
	int i = 0;
public:
	class Node {
	public:
		T data;
		Node* next;
		Node* previous;
	};
	Node* head = NULL;
	void InsertAtBeginning(T dat) {
		Node* newNode = new Node();
		newNode->data = dat;
		newNode->next = head;
		newNode->previous = NULL;
		if(head != NULL)
			head->previous = newNode;
		head = newNode;
		count++;
	}
	void InsertAfter(Node* node, T dat) {
		if (node == NULL) return;
		Node* newNode = new Node();
		newNode->data = dat;
		newNode->previous = node;
		newNode->next = node->next;
		node->next->previous = newNode;
		node->next = newNode;
		count++;

	}
	void InsertAtEnd(T dat) {
		Node* LastNode = head;
		while (LastNode->next != NULL) {
			LastNode = LastNode->next;
		}
		Node* newNode = new Node();
		newNode->data = dat;
		newNode->previous = LastNode;
		LastNode->next = newNode;
		newNode->next = NULL;
		count++;

	}

	void DeleteNode(Node* node) {
		if (node == NULL || head == NULL) return;
		if(head == node)
		{
			head = node->next;
			if (head != NULL)
				head->previous = NULL;
			
			delete node;
			return;
		}
		if (node->previous != NULL) {
			node->previous->next = node->next;

		}
		if (node->next != NULL) {
			node->next->previous = node->previous;

		}
		delete node;
		count--;

	}
	void DeleteFistNode() {
		if (head == NULL) return;
		Node* temp = head;
		head = temp->next;
		if(head != NULL)
			head->previous = NULL;

		delete temp;
		count--;

	}
	void DeleteLastNode() {
		if (head == NULL) return;
		Node* LastNode = head;
		while (LastNode->next != NULL) {
			LastNode = LastNode->next;
		}
		if (LastNode->previous != NULL) {
			LastNode->previous->next = NULL;
		}
		else
			head = NULL;
		delete LastNode;
		count--;

	}
	void PrintList() {
		Node* CurrentNode = head;
		while (CurrentNode != NULL) {
			cout << CurrentNode->data << endl;
			CurrentNode = CurrentNode->next;
		}
	}
	Node* Find(T dat) {
		Node* CurrentNode = head;
		while (CurrentNode != NULL) {
			if (CurrentNode->data == dat) {
				return CurrentNode;
			}
			CurrentNode = CurrentNode->next;
		}
		return NULL;
	}
	int Size() {
		return count;
	}
	bool IsEmpty() {
		return head == NULL;
	}
	void Clear() {
		while (count > 0) {
			DeleteFistNode();
		}
	}
	void Reverse() {
		Node* CurrentNode = head;
		while (CurrentNode != NULL) {
			Node* temp = CurrentNode;
			T dat = CurrentNode->data;
			CurrentNode = CurrentNode->next;
			DeleteNode(temp);
			InsertAtBeginning(dat);
		}
	}
	void Reverse2() {
		Node* Current = head;
		Node* temp = NULL;
		while (Current != NULL) {
			temp = Current->previous;
			Current->previous = Current->next;
			Current->next = temp;
			Current = Current->previous;
		}
		if(temp != NULL)
			head = temp->previous;
	}

	Node* GetNode(int index) {
		i = 0;
		Node* Current = head;
		while (Current != NULL) {
			if (i == index)
				return Current;
			Current = Current->next;
			i++;
		}
		return NULL;
	}
	void Update(int index, int dat) {
		i = 0;
		Node* Current = head;
		while (Current != NULL) {
			if (i == index)
				Current->data = dat;
			Current = Current->next;
			i++;
		}
	}
	T GetItem(int index) {
		Node* node = GetNode(index);
		if (node != NULL)
			return node->data;
		return NULL;
	}

	void InsertAfterIndex(int index, T dat) {
		InsertAfter(GetNode(index), dat);
	}
};




