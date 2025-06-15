
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void WriteFiles(string file, string dataToAppend) {
	fstream MyFile;
	MyFile.open(file, ios::out | ios::app); // write and Append
	if (MyFile.is_open()) {
		MyFile << dataToAppend;
		MyFile.close();
	}
}

void ReadFiles(string file) {
	fstream MyFile;
	MyFile.open(file, ios::in);
	if (MyFile.is_open()) {
		string line;
		while (getline(MyFile, line)) {
			cout << line << endl;
		}
		MyFile.close();
	}
}

void ReadFilesInVector(string file, vector<string>& data) {
	fstream MyFile;
	MyFile.open(file, ios::in);
	if (MyFile.is_open()) {
		string line;
		while (getline(MyFile, line)) {
			if(line != "")
				data.push_back(line);
		}
		MyFile.close();
	}
}


void SaveVectorToFile(string file, vector<string> data) {
	fstream MyFile;
	MyFile.open(file, ios::out);
	if (MyFile.is_open()) {
		for (string& line : data) {
			if(line != "")
				MyFile << line << endl;
		}
		MyFile.close();
	}
}

void testFn(void (*fn)(int, double)) {
	// testFn(ts);
}


void ts(int x, double y) {}




struct dyArray {
	int* data;
	int size;
	int capacity;
};


int main()
{
	//WriteFiles("ttFile.txt", "eiwjaij\njsfoaijoiewjak\njsodijefsfdjl");

	dyArray* dA = new dyArray[5];


	vector<string> data;
	ReadFilesInVector("ttFile.txt", data);
	for (string &i : data) {
		// cout << i << endl;
		if (i == "jsodijefsfdjleiwjaij") i = "";
	}
	SaveVectorToFile("ttFile.txt", data);
	ReadFilesInVector("ttFile.txt", data);
	for (string& i : data) {
		cout << i << endl;
	}
	system("pause>0");
	return 0;

}



