/*
2. Zastosowania listy do implementacji tablicy rzadkiej. Proszę napisać
trzy funkcje:
- void init(node *&tab) – inicjalizującą tablicę,
- int value(node *tab, int n) – zwracającą wartość elementu o indeksie n,
- void set(node *&tab, int n, int value) – postawiającą wartość value pod
indeks n.
*/
#include<iostream>
using namespace std;
struct Node {
	int value;
	int index;
	Node* next;
};

void init(Node*& tab) {
	tab->index = -1;
	tab->value = 0;
	tab->next = NULL;
}

int value(Node* tab, int n) {
	while (tab != NULL && tab->index!=n) {
		tab = tab->next;
	}
	if (tab!=NULL) return tab->value;
	else return -1;
}

void setElement(Node*& tab, int n, int val) {
	if (tab == NULL) {
		Node* nowy = new Node;
		nowy->index = n;
		nowy->value = val;
		nowy->next = NULL;
		tab = nowy;
		return;
	}
	Node* tmp = tab;
	Node* prev = new Node;
	while (tmp->next!= NULL && tmp->next->index < n) {
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
		nowy->next = tmp->next;
		tmp->next = nowy;
	}
}

void print(Node* tab) {
	while (tab != NULL) {
		cout << tab->index << ":" << tab->value << ", ";
		tab = tab->next;
	}
	cout << endl;
}
int main() {
	Node* tab=new Node;
	init(tab);
	print(tab);
	setElement(tab, 0, 12);
	setElement(tab, 3, 16);
	setElement(tab, 11, 128);
	setElement(tab, 32, 1);
	setElement(tab, 67, 7);
	print(tab); 
	setElement(tab, 89, 5);
	print(tab);
	setElement(tab, 36, 4);
	print(tab);
	setElement(tab, 11, 16);
	print(tab);
	cout << value(tab, 67) << endl;
	cout << value(tab, 36);

}