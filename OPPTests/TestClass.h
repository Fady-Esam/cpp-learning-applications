#pragma once
#include<iostream>
using namespace std;

namespace TestClass {

	class Car
	{
		private:
			int t;
			float r;
			string f;
		public:
			Car(int t, float r, string f);
			void display();

	};
}

