
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
		newNode->next = newNode; //tự trỏ
		return;
	}
	node* tail = head; //đuôi
	while (tail->next != head) {
		tail = tail->next;
	}
	newNode->next = head;
	head = newNode;
	tail->next = newNode;
}
int main()
{
	node* head = NULL;
	for (int i = 1; i <= 10; i++) {
		themDau(head, i);
	}
	print(head);
}

