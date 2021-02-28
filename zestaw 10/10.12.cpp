/*
12. Proszę napisać funkcję, która otrzymując jako parametr wskazujący na
początek listy jednokierunkowej, przenosi na początek listy te z nich,
które mają parzystą ilość piątek w zapisie ósemkowym
*/
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
bool zap8(int n) {
	int licznik5 = 0;
	while (n > 0) {
		if (n % 8 == 5) licznik5++;
		n /= 8;
	}
	if (licznik5 % 2 == 0) return true;
	else return false;
}
void naPoczatek(Node*& head) {
	if (head != NULL) {
		Node* tmp = head;
		while (tmp->next != NULL) {
			if (zap8(tmp->next->value)) {
				Node* tmp2 = tmp->next;
				tmp->next = tmp->next->next;
				tmp2->next = head;
				head = tmp2;
			}
			else tmp = tmp->next;
		}
	}
}

void print(Node* head) {
	while (head != NULL) {
		cout << head->value << ",";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node *head= new Node;
	Node *a= new Node;
	Node *b= new Node;
	Node *c= new Node;
	Node *d= new Node;
	head->value = 13;
		head->next = a;
		a->value = 90;
		a->next = b;
	b->value = 93;
		b->next = c;
		c->value = 3421;
		c->next = d;
	d->value = 128;
		d->next = NULL;
		print(head);
		naPoczatek(head);
		print(head);
		cout << "g";
}