
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
	node* tmp = head->next;
	cout << head->data << " ";
	while (tmp != head) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
}
void themDau(node*& head, int x) {
	node* newNode = makeNode(x);
	if (head == NULL) {
		head = newNode;
		return;
	}
	node* tail = head;
	while (tail->next != head) {
		tail = tail->next;
	}
	newNode->next = head;
	head = newNode;
	tail->next = newNode;
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

void themGiua(node*& head, int x,int k) {
	node* newNode = makeNode(x);
	if (k < 1) {
		themDau(head, x);
		return;
	}
	if (k > demNode(head) + 1) {
		themCuoi(head, x);
		return;
	}
	node* tmp = head;
	for (int i = 1; i <= k - 2; i++) {
		tmp = tmp->next;
	}
	newNode->next = tmp->next;
	tmp->next = newNode;
}
int main()
{
	node* head = NULL;
	for (int i = 1; i <= 10; i++) {
		themCuoi(head, i);
	}
	themGiua(head, 100, 5);
	print(head);
}

