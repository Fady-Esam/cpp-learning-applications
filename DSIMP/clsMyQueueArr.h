#pragma once

#include<iostream>
#include "clsDynamicArray.h"
using namespace std;


template<class T>
class clsMyQueueArr {
protected:
	clsDynamicArray<T> MyQueue;
public:
	void push(T value) {
		MyQueue.InsertAtEnd(value);
	}
	void Pop() {
		MyQueue.DeleteFirstItem();
	}
	T front() {
		return MyQueue.GetItem(0);
	}
	T back() {
		return MyQueue.GetItem(MyQueue.size - 1);
	}
	void Print() {
		MyQueue.print();
	}
};


