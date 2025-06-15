#pragma once

#include<iostream>
using namespace std;

template<class T>
class clsDynamicArray {
	T* dynamicArray;
public:
	int size = 0;
	clsDynamicArray(int size = 0) {
		dynamicArray = new T[size];
		this->size = size;
	}
	~clsDynamicArray() {
		delete[] dynamicArray;
	}
	void setItem(int index, T value) {
		*(dynamicArray + index) = value;
		
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << *(dynamicArray + i) << endl;
		}
	}
	bool IsEmpty() {
		return size == 0;
	}
	void Resize(int newSize) {
		T* copyDynamicArray = dynamicArray;
		dynamicArray = new T[newSize];
		for (int i = 0; i < newSize; i++) {
			*(dynamicArray + i) = *(copyDynamicArray + i);
		}
		delete[] copyDynamicArray;
		size = newSize;
	}
	void Reverse() {
		T* copyDynamicArray = new T[size];
		for (int i = size - 1, j = 0; i >= 0; i--, j++) {
			*(copyDynamicArray + j) = *(dynamicArray + i);
		}
		delete[] dynamicArray;
		dynamicArray = copyDynamicArray;
	}

	T GetItem(int index) {
		return *(dynamicArray + index);
	}

	void Clear() {
		size = 0;
		dynamicArray = new T[size];
	}
	void DeleteItemAtIndex(int index) {
		T* copyDynamicArray = new T[size];
		for (int i = 0, j = 0; i < size; i++, j++) {
			if (i == index) {
				size--;
				j++;
			}
			*(copyDynamicArray + i) = *(dynamicArray + j);
		}
		delete[] dynamicArray;
		dynamicArray = copyDynamicArray;
	}

	void DeleteFirstItem() {
		DeleteItemAtIndex(0);
	}
	void DeleteLastItem() {
		DeleteItemAtIndex(size - 1);
	}
	int Find(T value) {
		for (int i = 0; i < size; i++) {
			if (*(dynamicArray + i) == value) {
				return i;
			}
		}
		return -1;
	}
	void DeleteItemByValue(T value) {
		DeleteItemAtIndex(Find(value));
	}
	void InsertAt(int index, T value) {
		size++;
		T* copyDynamicArray = new T[size];
		for (int i = 0, j = 0; i < size; i++, j++) {
			if (i == index) {
				*(copyDynamicArray + i) = value;
				i++;
			}
			*(copyDynamicArray + i) = *(dynamicArray + j);
		}
		delete dynamicArray;
		dynamicArray = copyDynamicArray;
	}
	void InsertBefore(int index, T value) {
		InsertAt(index < 1 ? 0 : index - 1, value);
	}	
	void InsertAfter(int index, T value) {
		InsertAt(index >= size ? size: index + 1, value);
	}
	void InsertAtBegining(T value) {
		InsertAt(0, value);
	}
	void InsertAtEnd(T value) {
		InsertAt(size, value);
	}
};


