
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <climits>
#include <iomanip>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
struct Room {
	int roomNumber;
	string roomClassify;
	int roomStatus;
	string ten;
};

struct node {
	Room data;
	node* next;
};

node* makeNode(Room x) {
	node* newNode = new node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void themCuoi(node*& head, Room x) {
	node* newNode = makeNode(x);
	if (head == NULL) {
		head = newNode;
		return;
	}
	node* tmp = head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = newNode;
}

void init(node*& head) {
	for (int i = 1; i <= 10; i++) {
		Room room;
		if (i <= 2) {
			room.roomClassify = "RR";
		}
		else if (i <= 5) {
			room.roomClassify = "DB";
		}
		else room.roomClassify = "TC";
		room.roomNumber = i;
		room.roomStatus = 0;
		room.ten = "EMPTY";
		themCuoi(head, room);
	}
}

void print(Room room) {
	cout << room.roomNumber << " " << room.roomClassify << " " << room.roomStatus << " " << room.ten << endl;
}

void printList(node* head) {
	while (head != NULL) {
		print(head->data);
		head = head->next;
	}
}

void checkIn(node* head) {
	Room room;
	string classifyRoom;
	do {
		cout << "Enter the room classify : ";
		getline(cin, classifyRoom);
		if (classifyRoom != "RR" && classifyRoom != "TC" && classifyRoom != "DB") {
			cout << "Re-enter the room classisfy : " << endl;
		}
	} while (classifyRoom != "RR" && classifyRoom != "TC" && classifyRoom != "DB");
	node* tmp = head;
	while (tmp != NULL) {
		if (tmp->data.roomClassify == classifyRoom && tmp->data.roomStatus == 0) {
			print(tmp->data);
		}
		tmp = tmp->next;
	}
	int num;
	cout << "Enter the room number : ";
	cin >> num;
	cin.ignore();
	tmp = head;
	while (tmp != NULL) {
		if (tmp->data.roomNumber == num && tmp->data.roomStatus == 0 && tmp->data.roomClassify == classifyRoom) {
			tmp->data.roomStatus = 1;
			string name;
			cout << "Enter the name : ";
			getline(cin, name);
			tmp->data.ten = name;
		}
		tmp = tmp->next;
	}
}
void checkOut(node* head) {
	int num;
	cout << "Enter the room number : ";
	cin >> num;
	node* tmp = head;
	while (tmp != NULL) {
		if (tmp->data.roomNumber == num) {
			tmp->data.roomStatus = 0;
			tmp->data.ten = "EMPTY";
			break;
		}
		tmp = tmp->next;
	}
}

void menu() {
	node* head = NULL;
	init(head); 
	int op;
	do {
		system("cls");
		cout << "0. Exit  " << "1.Check In  " << "2. Check out  " << "3. Output  " << endl;
		cout << "Option : ";
		cin >> op;
		cin.ignore();
		if (op == 0) break;
		else if (op == 1) checkIn(head);
		else if (op == 2) checkOut(head);
		else printList(head);
		system("pause");
	} while (op >= 1 && op <= 3);
}

int main()
{
	menu();
}

