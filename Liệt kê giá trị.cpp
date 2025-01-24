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
struct Node
{
    int data;
    Node* next;
    Node* prev;
};
typedef Node* node;
node makeNode(int x)
{
    node tmp = new Node();
    tmp->data = x;
    tmp->next = nullptr;
    tmp->prev = nullptr;
    return tmp;
}
void insertLast(node& head, int x)
{
    node newnode = makeNode(x);
    if (head == nullptr)
    {
        head = newnode;
        return;
    }
    node tmp = head;
    while (tmp->next != NULL)
    {
        if (tmp->data == x) return;
        tmp = tmp->next;
    }
    if (tmp->data == x) return;
    newnode->prev = tmp;
    tmp->next = newnode;
}

void Print(node a)
{
    while (a != nullptr)
    {
        cout << a->data << " ";
        a = a->next;
    }
}
int main()
{
    node head = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        insertLast(head, x);
    }
    Print(head);
}
