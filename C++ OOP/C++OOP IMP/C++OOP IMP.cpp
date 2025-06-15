

#include <iostream>
#include <vector>
#include <string>
#include<fstream>

using namespace std;


struct Client {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

void ReadClientData(Client& ct) {
	cout << "Enter Account Number ";
	cin >> ct.AccountNumber;
	cout << "Enter PinCode ";
	cin >> ct.PinCode;
	cout << "Enter Your Name ";
	cin >> ct.Name;
	cout << "Enter Your Phone ";
	cin >> ct.Phone;
	cout << "Enter Account Balance ";
	cin >> ct.AccountBalance;
	cout << endl;
}




string GetClientData(Client ct, string sep) {
	return ct.AccountNumber + sep + ct.PinCode + sep + ct.Name + sep + ct.Phone + sep + to_string(ct.AccountBalance);
	
}

vector<string> Split(string s, string c) {
	vector<string> v;
	string temp = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != c[0])
			temp += s[i];
		if (s[i] == c[0] || i == s.length() - 1) {
			v.push_back(temp);
			temp = "";
			i += c.length() - 1;
		}
	}
	return v;
}
Client ConvertRecordToStruct(string rec, string sep) {
	Client NewClient;
	vector<string> s = Split(rec, sep);
		NewClient.AccountNumber = s[0];
		NewClient.PinCode = s[1];
		NewClient.Name = s[2];
		NewClient.Phone = s[3];
		NewClient.AccountBalance = stod(s[4]);	
		return NewClient;
}

void SaveClientToFile(string FileName, string record) {
	fstream f;
	f.open(FileName, ios::out | ios::app);
	if (f.is_open()) {
		f << record << endl;
		f.close();
	}

}

vector<Client> FillVector(string FileName) {
	vector<Client> v;
	fstream f;
	f.open(FileName, ios::in);
	if (f.is_open()) {
		string line;
		while (getline(f, line)) {
			if (line != "") {
				v.push_back(ConvertRecordToStruct(line, "#//#"));
			}
		}
		f.close();
	}
	return v;
}





void SetClientsFromVectorToFile(string FileName, vector<Client> v) {
	fstream f;
	f.open(FileName, ios::out);
	if (f.is_open()) {
		for (Client& i : v) {
			f << GetClientData(i, "#//#") << endl;
		}
		f.close();
	}
}

#include<iomanip>;

void ShowAllClients(string FileName) {
	// Print Header with number of clients
	vector<Client> v = FillVector(FileName);
	int totalClients = v.size();
	string title = "Clients List (" + to_string(totalClients) + " Clients)";
	int width = 78;  // Width of the output table
	cout << setfill('=') << setw(width) << "" << endl;  // Top border
	cout << setw((width + title.length()) / 2) << title << endl;
	cout << setfill('=') << setw(width) << "" << endl;  // Bottom border

	// Print Column Headers
	cout << left << setw(20) << "Account Number"
		<< setw(15) << "Pin Code"
		<< setw(20) << "Name"
		<< setw(15) << "Phone"
		<< setw(10) << "Balance" << endl;
	cout << setfill('=') << setw(width) << "" << endl;  // Header separator

	// Print Clients Data
	for (const Client& c : v) {
		cout << left << setfill(' ') << setw(20) << c.AccountNumber
			<< setw(15) << c.PinCode
			<< setw(20) << c.Name
			<< setw(15) << c.Phone
			<< setw(10) << fixed << setprecision(2) << c.AccountBalance
			<< endl;
	}
	cout << setfill('=') << setw(width) << "" << endl;  // Bottom border
}






Client FindClient(string acNo) {
	vector<Client> v = FillVector("Clients.txt");
	for (Client& c : v) {
		if (c.AccountNumber == acNo) {

			return c;
		}
	}
	return Client();
}

bool DeleteClient(string acNo) {
	vector<Client> v = FillVector("Clients.txt");
	vector<Client>::iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		if ((*it).AccountNumber == acNo) {
			v.erase(it);
			SetClientsFromVectorToFile("Clients.txt", v);
			return true;
		}
	}
	return false;
}


void ReadToUpdate(Client& ct) {
	ct.AccountNumber = ct.AccountNumber;
	cout << "Enter PinCode ";
	cin >> ct.PinCode;
	cout << "Enter Your Name ";
	cin >> ct.Name;
	cout << "Enter Your Phone ";
	cin >> ct.Phone;
	cout << "Enter Account Balance ";
	cin >> ct.AccountBalance;
	cout << endl;

}



bool UpdateClients(string acNo) {
	vector<Client> v = FillVector("Clients.txt");
	for (Client& C : v) {
		if (C.AccountNumber == acNo) {
			ReadToUpdate(C);
			SetClientsFromVectorToFile("Clients.txt", v);
			return true;
		}
	}

	return false;
}







int main()
{
	//char ans = 'y';
	//do {
	//	Client ct;
	//	ReadClientData(ct);
	//	SaveClientToFile("Clients.txt", GetClientData(ct, "#//#"));
	//	cout << "Do You Want to Add New Data ";
	//	cin >> ans;
	//} while (ans == 'y');
	cout << "======================== \n";

	//DeleteClient("489423");
	UpdateClients("111");
	ShowAllClients("Clients.txt");
	system("pause>0");
	return 0;
	//cout << ConvertRecordToStruct(PrintClientData(ct, "#//#"), "#//#").Name;
}

