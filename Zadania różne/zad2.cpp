/*
2. Zastosowania listy do implementacji tablicy rzadkiej. Proszę napisać
trzy funkcje:
- void init(node *&tab) – inicjalizującą tablicę,
- int value(node *tab, int n) – zwracającą wartość elementu o indeksie n,
- void set(node *&tab, int n, int value) – postawiającą wartość value pod
indeks n.
*/
#include <iostream>
using namespace std;
struct Node {
	int value;
	int index;
	Node* next;
};
int value(Node* tab, int n) {
	while (tab !=NULL && tab->index < n) {
		tab = tab->next;
	}
	if (tab == NULL || tab->index>n) return -1;
	if (tab->index == n) return tab->value;
}
void set(Node*& tab, int n, int val) {
	Node* helper = new Node;
	helper->next = tab;
	Node* tmp = helper;
	while (tmp->next != NULL && tmp->next->index < n) {
		tmp = tmp->next;
	}
	if (tmp->next == NULL) {
		Node* nowy = new Node;
		nowy->value = val;
		nowy->index = n;
		nowy->next = NULL;
		tmp->next = nowy;
	}
	else if (tmp->next->index == n) {
		tmp->next->value = val;
	}
	else {
		Node* nowy = new Node;
		nowy->value = val;
		nowy->index = n;
		Node* temp = tmp->next;
		tmp->next = nowy;
		nowy->next = temp;
	}
	tab = helper->next;
	delete helper;
}
void addBack(Node*& head, int val,int idx) {
	Node* nowy = new Node;
	nowy->value = val;
	nowy->index = idx;
	nowy->next = NULL;
	if (head == NULL) head = nowy;
	else {
		Node* tmp = head;
		while (tmp->next != NULL) tmp = tmp->next;
		tmp->next = nowy;
	}
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << ","<< head->index << "  ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head = NULL;
	addBack(head, 2,0);
	addBack(head, 7,21);
	addBack(head, 18,43);
	addBack(head, 22,107);
	addBack(head, 3,989);
	print(head);
	cout << value(head, 40)<< endl;
	cout << value(head, 0)<< endl;
	cout << value(head, 43)<< endl;
	cout << value(head, 989)<< endl;
	set(head, 1003, 9);
	set(head, 43, 7);
	set(head, 22, 103);
	print(head);

}