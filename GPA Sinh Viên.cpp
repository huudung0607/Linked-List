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
struct SinhVien {
	string ma, hoTen; double gpa;
	friend istream& operator >> (istream& in, SinhVien& x) {
		in >> x.ma;
		in.ignore();
		getline(in, x.hoTen);
		in >> x.gpa;
		return in;
	}
	friend ostream& operator << (ostream& out, SinhVien x) {
		out << x.ma << " " << x.hoTen << " " << fixed << setprecision(2) << x.gpa;
		return out;
	}
};

struct Node {
	SinhVien data;
	Node* next;
	Node(SinhVien x) {
		data = x;
		next = NULL;
	}
};
typedef Node* node;

double gpa = 0;
void last(node& a, SinhVien x) {
	gpa = max(x.gpa, gpa);
	node tmp = new Node(x);
	if (a == NULL) a = tmp;
	else {
		node p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = tmp;
	}
}

void in(node a) {
	while (a != NULL) {
		if (a->data.gpa == gpa)cout << a->data << endl;
		a = a->next;
	}
}
int main() {
	node a = NULL;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		SinhVien x; cin >> x;
		last(a, x);
	}
	in(a);
}
