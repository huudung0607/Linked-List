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
    string data;
    int freq;
    Node* next;
    Node(string x) {
        data = x;
        freq = 1;
        next = NULL;
    }
};
typedef Node* node;
void insertOrUpdate(node& head, string word) {
    node p = head;
    node prev = NULL;
    while (p != NULL) {
        if (p->data == word) {
            p->freq++;
            return;
        }
        prev = p;
        p = p->next;
    }
    node newNode = new Node(word);
    if (head == NULL) {
        head = newNode;
    }
    else {
        prev->next = newNode; 
    }
}
void print(node head) {
    node p = head;
    while (p != NULL) {
        cout << p->data << " " << p->freq << endl;
        p = p->next;
    }
}
int main() {
    node head = NULL; 
    string line;
    while (getline(cin, line)) { 
        stringstream ss(line);
        string word;
        while (ss >> word) {
            insertOrUpdate(head, word);
        }
    }
    print(head);
}
