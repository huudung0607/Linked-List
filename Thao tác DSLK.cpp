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
struct node
{
	int data;
	node* next;
};
node* makenode(int x)
{
	node* newNode = new node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void print(node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
int demnode(node* head)
{
	int cnt = 0;
	while (head != NULL)
	{
		cnt++;
		head = head->next;
	}
	return cnt;
}
void themdau(node*& head,int x)
{
	node* newNode = makenode(x);
	newNode->next = head;
	head = newNode;
}
void themcuoi(node*& head, int x)
{
	node* newNode = makenode(x);
	node* tmp = head;
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = newNode;
}
void themgiua(node*& head, int x, int k)
{
	node* newNode = makenode(x);
	node* tmp = head;
	if (k < 1 || k > demnode(head) + 1)
	{
		return;
	}
	if (k == 1)
	{
		head = newNode;
		return;
	}
	for (int i = 1; i <= k - 2; i++)
	{
		tmp = tmp->next;
	}
	newNode->next = tmp->next;
	tmp->next = newNode;
}
void xoadau(node*& head)
{
	if (head == NULL)
	{
		return;
	}
	node* xoa = head;
	head = head->next;
	delete xoa;
}
void xoacuoi(node*& head)
{
	if (head == NULL)
	{
		return;
	}
	node* tmp = head;
	if (tmp->next == NULL)
	{
		head = NULL;
		delete tmp;
		return;
	}
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
	if (k < 1 || k > demnode(head) + 1)
	{
		return;
	}
	node* tmp = head;
	if (k == 1)
	{
		head = head->next;
		delete tmp;
		return;
	}
	for (int i = 1; i <= k - 2; i++)
	{
		tmp = tmp->next;
	}
	node* xoa = tmp->next;
	tmp->next = tmp->next->next;
	delete xoa;
}
int main() {
	node* head = makenode(100);
	
}
