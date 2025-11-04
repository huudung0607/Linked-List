
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

struct node {
	int data;
	node* next;
};

node* makeNode(int x) {
	node* newNode = new node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

int demNode(node* head) {
	int dem = 1;
	node* tail = head->next;
	while (tail != head) {
		dem++;
		tail = tail->next;
	}
	return dem;
}

void print(node* head) {
	if (head == NULL) return;
	node* tmp = head;
	do {
		cout << tmp->data << " ";
		tmp = tmp->next;
	} while (tmp != head);
}
void themCuoi(node*& head,int x) {
	node* newNode = makeNode(x);
	if (head == NULL) {
		head = newNode;
		newNode->next = newNode;
		return;
	}
	node* tail = head;
	while (tail->next != head) {
		tail = tail->next;
	}
	tail->next = newNode;
	newNode->next = head;
}
void xoaCuoi(node*& head) {
	if (head == NULL) {
		return;
	}
	if (head->next == head) {
		delete head;
		head = NULL;
		return;
	}
	node* tail = head;
	while (tail->next->next != head) {
		tail = tail->next;
	}
	node* xoa = tail->next;
	tail->next = head;
	delete xoa;
}
int main()
{
	node* head = NULL;
	for (int i = 1; i <= 10; i++) {
		themCuoi(head, i);
	}
	xoaCuoi(head);
	print(head);
}

