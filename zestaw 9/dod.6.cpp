#include <iostream>
using namespace std;
struct Node {
	int key;
	Node* next;
};
/*
6. Lista zawiera niepowtarzające się elementy. Proszę napisać funkcję do
której przekazujemy wskaźnik na początek oraz wartość klucza. Jeżeli
element o takim kluczu występuje w liście należy go usunąć z listy. Jeżeli
elementu o zadanym kluczu brak w liście należy element o takim kluczu
wstawić do listy.
*/

void cosRobi(Node*& head, int n) {
	if (head == NULL) {
		Node* nowy = new Node;
		nowy->key = n;
		nowy->next = NULL;
		head = nowy;
	}
	else if (head->key == n) {
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
	else {
		Node* tmp = head;
		while (tmp->next != NULL && tmp->next->key != n) {
			tmp = tmp->next;
		}
		if (tmp->next == NULL) {
			Node* nowy = new Node;
			nowy->key = n;
			nowy->next = NULL;
			tmp->next = nowy;
		}
		else {
			Node* tmp1 = tmp->next;
			tmp->next = tmp->next->next;
			delete tmp1;
		}
	}
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->key << ",";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head= new Node;
	Node* a= new Node;
	Node* b= new Node;
	Node* c= new Node;
	head->key =0;
	head->next =a;
	a->key =1;
	a->next =b;
	b->key =2;
	b->next =c;
	c->key =3;
	c->next =NULL;
	print(head);
	cosRobi(head, 9);
	print(head);
}

