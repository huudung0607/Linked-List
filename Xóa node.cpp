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
void in(node a)
{
	if (a == NULL)
	{
		cout << "EMPTY";
	}
	while (a != NULL)
	{
		cout << a->data << " ";
		a = a->next;
	}
}
void deleteALL(node& a, int x)
{
	node first = NULL, last = a;
	while (last != NULL)
	{
		if (last->data == x)
		{
			if (first == NULL)
			{
				a = a->next;
				last = a;
			}
			else
			{
				first->next = last->next;
				last = first->next;
			}
		}
		else
		{
			first = last;
			last = last->next;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node a = NULL;
	int n, value;
	cin >> n >> value;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		insert(a, x);
	}
	deleteALL(a, value);
	in(a);
}
