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
	int data;
	Node* next;
	Node(int x)
	{
		data = x;
		next = NULL;
	}
};
typedef Node* node;
void insert(node& a, int x)
{
	node tmp = new Node(x);
	if (a == NULL)
	{
		a = tmp;
	}
	else
	{
		node p = a;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = tmp;
	}
}
void push(node& a, int x)
{
	node tmp = new Node(x);
	if (a == NULL) a = tmp;
	else {
		tmp->next = a;
		a = tmp;
	}
}

void in(node a)
{
	if (a == NULL)
	{
		cout << "EMPTY" << endl;
	}
	while (a != NULL)
	{
		cout << a->data << " ";
		a = a->next;
	}
	cout << endl;
}
void pop(node& a)
{
	if (a == NULL)
	{
		return;
	}
	a = a->next;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node a = NULL;
	int n; cin >> n;
	while (n--) {
		string tt; cin >> tt;
		if (tt == "push") {
			int x; cin >> x;
			push(a, x);
		}
		else if (tt == "pop") {
			pop(a);
		}
		else {
			in(a);
		}
	}
}
