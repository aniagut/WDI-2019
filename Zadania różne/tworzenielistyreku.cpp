/*
VI kartkówka - WSKAŹNIKI + REKURENCJA (obie grupy)
- napisz funkcję rekurencyjną, która utworzy 1-kierunkową listę o kolejnych elementach naturalnych
mniejszych bądź równych n
*/
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
Node* tworzy(int val, int n) {
	if (n > val) return NULL;
	Node* result = new Node;
	result->value = n;
	result->next = tworzy(val, n+1);
	return result;
}
void print(Node* head) {
	while (head) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	print(tworzy(6,0));
}