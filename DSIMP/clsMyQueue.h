#pragma once
#include<iostream>
#include "clsDBlLinkedList.h"

using namespace std;

template<class T>
class clsMyQueue {
protected:
	clsDBlLinkedList<int> list;
public:
	void push(T value) {
		list.InsertAtEnd(value);
	}
	void Pop() {
		list.DeleteFistNode();
	}
	T front() {
		return list.GetItem(0);
	}
	T back() {
		return list.GetItem(list.Size() - 1);
	}
	void Print() {
		list.PrintList();
	}
};


