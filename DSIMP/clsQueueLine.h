#pragma once

#include<iostream>
#include<queue>
#include<stack>

#include<string>

using namespace std;

class clsQueueLine {
	string QueueLinePrefix;
	int minutesPerClient = 0;
	int ServedClients = 0;
	int count = 0;
	class Ticket {
	public:
		string TicketPrefix;
		int minuteTicket = 0;
		int numWaitingClient = 0;
		Ticket(string pr, int min, int nw) {
			TicketPrefix = pr;
			minuteTicket = min;
			numWaitingClient = nw;
		}


	};
	queue<Ticket> tickets;
public:
	clsQueueLine(string p, int m) {
		QueueLinePrefix = p;
		minutesPerClient = m;
	}

	void IssueTicket() {
		Ticket newTicket(QueueLinePrefix + to_string(count + 1), minutesPerClient * count, count);
		count++;
		tickets.push(newTicket);
	}

	void PrintInfo() {
		cout << "Prefix \n";
		cout << QueueLinePrefix << endl;
		cout << "Total Tickets \n";
		cout << tickets.size() << endl;
		cout << "Served Clients \n";
		cout << ServedClients << endl;
		cout << "Waiting Clients \n";
		cout << tickets.size() << endl;
	}

	void PrintTnfoTickets() {
		queue<Ticket> ts = tickets;
		while (!ts.empty()) {
			Ticket t = ts.front();
			cout << t.TicketPrefix << endl;
			cout << " Minutes Remaining \n";
			cout << t.minuteTicket << endl;
			cout << " Num Waiting Clients \n";
			cout << t.numWaitingClient << endl;
			ts.pop();
			cout << endl << endl;
		}
	}


	void ServeClient() {
		tickets.pop();
		ServedClients++;
	}

};