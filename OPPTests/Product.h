#pragma once

#include<iostream>
using namespace std;

class Product {
private:
	int id = 1;
	int qty;
	double price;
	string productName;
public:
	Product(int qty, double price, string productName) {
		this->qty = qty;
		this->price = price;
		this->productName = productName;
	}
	void displayData() {
		cout << "Quantity is equal " << qty << endl;
	}
};
