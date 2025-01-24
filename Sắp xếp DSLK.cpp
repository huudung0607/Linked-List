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
void First(node& a, int x)
{
    node tmp = new Node(x);
    if (a == NULL) a = tmp;
    else
    {
        tmp->next = a;
        a = tmp;
    }
}
void SapXep_Tang(node& a)
{
    for (node p = a; p->next != NULL; p = p->next)
    {
        for (node q = p; q != NULL; q = q->next)
        {
            if (p->data > q->data)
            {
                swap(p->data, q->data);
            }
        }
    }
}
void SapXep_Giam(node& a)
{
    for (node p = a; p->next != NULL; p = p->next)
    {
        for (node q = p; q != NULL; q = q->next)
        {
            if (p->data < q->data)
            {
                swap(p->data, q->data);
            }
        }
    }
}
void Print(node a)
{
    while (a != NULL)
    {
        cout << a->data << " ";
        a = a->next;
    }
}
int main()
{
    node a = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        First(a, x);
    }
    SapXep_Tang(a);
    Print(a);
    SapXep_Giam(a);
    cout << endl;
    Print(a);
}
