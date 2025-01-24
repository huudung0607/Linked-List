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
struct sinhvien {
	string msv, hoten;
	double gpa;
	friend istream& operator >> (istream& in, sinhvien& sv) {
		in >> sv.msv;
		in.ignore();
		getline(in, sv.hoten);
		in >> sv.gpa;
		return in;
	}
	friend ostream& operator << (ostream& out, sinhvien sv)
	{
		out << sv.msv << " " << sv.hoten << " " << fixed << setprecision(2) << sv.gpa;
		return out;
	}
};
struct Node {
	sinhvien data;
	Node* next;
	Node(sinhvien x)
	{
		data = x;
		next = NULL;
	}
};
typedef Node* node;
void first(node& a, sinhvien x)
{
	node tmp = new Node(x);
	if (a == NULL)
	{
		a = tmp;
	}
	else
	{
		tmp->next = a;
		a = tmp;
	}
}
void last(node& a, sinhvien x)
{
	node tmp = new Node(x);
	if (a == NULL)
	{
		a = tmp;
	}
	else
	{
		node p = a;
		while (p ->next != NULL)
		{
			p = p->next;	
		}
		p->next = tmp;
	}
}
void mid(node& a, sinhvien x,int k)
{
	if (k == 1)
	{
		first(a, x);
	}
	else
	{
		node p = a;
		for (int i = 1; i <= k - 2; i++)
		{
			p = p->next;
		}
		node tmp = new Node(x);
		tmp->next = p->next;
		p->next = tmp;
	}
}
void in(node a)
{
	while (a != NULL)
	{
		cout << a->data << endl;
		a = a->next;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node a = NULL;
	int t;
	cin >> t;
	while (t--)
	{
		int c;
		cin >> c;
		if (c == 1)
		{
			sinhvien x;
			cin >> x;
			first(a, x);
		}
		if (c== 2)
		{
			sinhvien x;
			cin >> x;
			last(a, x);
		}
		if (c== 3)
		{
			int k; cin >> k;
			sinhvien x;
			cin >> x;
			mid(a, x, k);
		}
	}
	in(a);
}
