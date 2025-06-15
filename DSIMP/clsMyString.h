#pragma once
#include<iostream>
#include<stack>

#include "clsMyString.h"
using namespace std;


class clsMyString {
	stack<string> Undo;
	stack<string> Redo;
	string val;
public:
	void SetValue(string v) {
		Undo.push(val);
		val = v;

	}
	string GetValue() {
		return val;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;
	void UndoFn() {
		Redo.push(val);
		val = Undo.top();
		Undo.pop();
	}
	void RedoFn() {
		Undo.push(val);
		val = Redo.top();
		Redo.pop();
	}

};



