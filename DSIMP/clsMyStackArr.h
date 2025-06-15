#pragma once

#include<iostream>
#include "clsMyQueueArr.h"
using namespace std;

template<class T>
class clsMyStackArr : public clsMyQueueArr<T> {
	void push(T value) {
		clsMyQueueArr <T>::MyQueue.InsertAtBegining(value);
	}

	T Top() {
		clsMyQueueArr <T>::front();
	}

	T Bottom() {
		clsMyQueueArr <T>::back();
	}


};
