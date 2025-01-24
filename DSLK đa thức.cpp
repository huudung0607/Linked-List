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
struct Node {
	int heSo;
	int soMu;
	Node* next;
	Node(int hs, int sm) {
		heSo = hs;
		soMu = sm;
		next = NULL;
	}
};
typedef Node* node;

void insert(node& a, int hs, int sm) {
	node tmp = new Node(hs, sm);
	if (a == NULL) a = tmp;
	else {
		node p = a;
		while (p->next != NULL) {
			if (p->soMu == sm) {
				p->heSo += hs;
				return;
			}
			p = p->next;
		}
		if (p->soMu == sm) p->heSo += hs;
		else p->next = tmp;
	}
}
void sort(node& a) {
	for (node p = a; p != NULL; p = p->next) {
		for (node q = p->next; q != NULL; q = q->next) {
			if (p->soMu < q->soMu) {
				swap(p->soMu, q->soMu);
				swap(p->heSo, q->heSo);
			}
		}
	}
}

void print(node a) {
	while (a != NULL) {
		cout << a->heSo << "x^" << a->soMu;
		if (a->next != NULL) cout << " + ";
		a = a->next;
	}
}
int main() {
	node a = NULL;
	string x;
	while (cin >> x) {
		if (x == "+") continue;
		int pos = x.find("x");
		int hs = stoi(x.substr(0, pos));
		int sm = stoi(x.substr(pos + 2));
		insert(a, hs, sm);
	}
	sort(a);
	print(a);
}
