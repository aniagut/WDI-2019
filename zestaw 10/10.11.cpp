#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
/*
11. Proszę napisać funkcję, która otrzymując jako parametr wskazujący na
początek listy jednokierunkowej, usuwa z niej wszystkie elementy, w których
wartość klucza w zapisie trójkowym ma większą ilość jedynek niż dwójek.
*/
bool zapisy(int n) {
	int licznik1 = 0;
	int licznik2 = 0;
	while (n > 0) {
		if (n % 3 == 2) licznik2++;
		if (n % 3 == 1)licznik1++;
		n /= 3;
	}
	if (licznik1 > licznik2) return true;
	else return false;
}
void del(Node*& head) {
		while (head != NULL && zapisy(head->value)) {
				head = head->next;
		}
		if (head != NULL) {
			Node* tmp = head;
			while (tmp->next != NULL) {
				if (zapisy(tmp->next->value)) {
					Node* tmp1 = tmp->next;
					tmp->next = tmp->next->next;
					delete tmp1;
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
	Node *head =new Node;
	Node *a =new Node;
	Node *b=new Node;
	Node *c=new Node;
	Node *d=new Node;
	head->value = 0;
	head->next = a;
	a->value = 113;
	a->next = b;
	b->value = 2;
	b->next = c;
	c->value = 781;
	c->next = d;
	d->value = 128;
	d->next = NULL;
	print(head);
	del(head);
	print(head);
}