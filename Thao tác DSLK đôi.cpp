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
	node* prev;
	node* next;
};
void duyet(node* head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
node* makenode(int x)
{
	node* newNode = new node;
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
int sz(node* head)
{
	int cnt = 0;
	while (head != NULL)
	{
		cnt++;
		head = head->next;
	}
	return cnt;
}
void themdau(node*& head, int x)
{
	node* newNode = makenode(x);	
	newNode->next = head;
	if (head !=NULL)
	{
		head->prev = newNode;
	}
	head = newNode;
}
void themcuoi(node*& head, int x)
{
	node* tmp = head;
	node* newNode = makenode(x);
	if (head ==NULL)
	{
		head = newNode;
		return;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = newNode;
	newNode->prev = tmp;
}
void themgiua(node*& head, int x, int k)
{
	if (k < 1 || k > sz(head) + 1)
	{
		return;
	}
	if (k == 1)
	{
		themdau(head, x);
		return;
	}
	node* newNode = makenode(x);
	node* tmp = head;
	for (int i = 1; i <= k - 1; i++)
	{
		tmp = tmp->next;
	}
	newNode->next = tmp;
	tmp->prev->next = newNode;
	newNode->prev = tmp->prev;
	tmp->prev = newNode;
}
void xoadau(node*& head)
{
	if (head == NULL)
	{
		return;
	}
	node* xoa = head;
	head = head->next;
	head->prev = NULL;
	delete xoa;
}
void xoacuoi(node*& head)
{
	if (head == NULL)
	{
		return;
	}
	if (head->next == NULL)
	{
		delete head;
		head = NULL;
		return;
	}
	node* tmp = head;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	node* xoa = tmp->next;
	tmp->next = NULL;
	delete xoa;
}
void xoagiua(node*& head, int k)
{
	if (k < 1 || k > sz(head) + 1)
	{
		return;
	}
	if (k == 1)
	{
		xoadau(head);
		return;
	}
	node* tmp = head;
	for (int i = 1; i <= k - 1; i++)
	{
		tmp = tmp->next;
	}
	node* xoa = tmp;
	tmp->prev->next = tmp->next;
	if (tmp->next != NULL)
	{
		tmp->next->prev = tmp->prev;
	}
	delete xoa;
}
int main()
{
	node* newnode = NULL;
	for (int i = 1; i <= 10; i++)
	{
		themdau(newnode, i);
	}
	themgiua(newnode, 999, 4);
	xoagiua(newnode,4);
	duyet(newnode);
}
