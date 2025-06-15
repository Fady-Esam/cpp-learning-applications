#pragma once


#include<iostream>
#include "clsDBlLinkedList.h"
#include "clsMyQueue.h";
using namespace std;

template<class T>
class clsMyStack : public clsMyQueue<T>{
public:
	void push(T value) {
		clsMyQueue<T>::list.InsertAtBeginning(value);
	}
	T Top() {
		clsMyQueue<T>::front();
	}
	T Bottom() {
		clsMyQueue<T>::back();
	}

};



