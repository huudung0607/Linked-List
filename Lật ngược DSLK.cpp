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
	node* prev;
};
node* makeNode(int x) {
	node* res = new node;
	res->data = x;
	res->next = NULL;
	res->prev = NULL;
	return res;
}
void themcuoi(node*& head, int x) {
	node* newNode = makeNode(x);
	node* tmp = head;
	if (head == NULL) {
		head = newNode; return;
	}
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = newNode;
	newNode->prev = tmp;
}
void duyet(node* head) {
	while (head->next != NULL) {

		head = head->next;
	}
	while (head != NULL) {
		cout << head->data << " ";
		head = head->prev;
	}
}
int main() {
	node* head = NULL;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		themcuoi(head, x);
	}
	duyet(head);
}
