#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* prev;
	Node* next;
};
/*
13. Proszę napisać funkcję, która otrzymując jako parametr wskazujący na
początek listy dwukierunkowej, usuwa z niej wszystkie elementy, w których
wartość klucza w zapisie binarnym ma nieparzystą ilość jedynek.
*/
bool ilosc1(int n) {
	int licznik1=0;
	while (n > 0) {
		if (n % 2 == 1) licznik1++;
		n /= 2;
	}
	if (licznik1 % 2 == 0) return false;
	else return true;
}
void del(Node*& head) {
	while (head != NULL && ilosc1(head->value)) {
		head = head->next;
		}
	if (head != NULL) {
		Node* tmp = head;
		while (tmp->next != NULL) {
			if (ilosc1(tmp->next->value)) {
				Node* tmp2 = tmp->next;
				tmp->next = tmp->next->next;
				if (tmp->next->next != NULL) {
					tmp->next->next->prev = tmp;
				}
				delete tmp2;
			}
			else tmp = tmp->next;
		}
	}	
}
void print(Node* head) {
	while (head != 0) {
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
	head->value = 9;
		head->next = a;
		head->prev = NULL;
		a->value = 124;
			a->next = b;
		a->prev = head;
		b->value = 43;
			b->next = c;
		b->prev = a;
		c->value = 87;
			c->next = d;
		c->prev = b;
		d->value = 95;
			d->next = NULL;
		d->prev = c;
		print(head);
		del(head);
		print(head);
}