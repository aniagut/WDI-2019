/*
18. Kolejne elementy listy o zwiększającej się wartości pola val nazywamy
podlistą rosnącą. Proszę napisać funkcję, która usuwa z listy wejściowej
najdłuższą podlistę rosnącą. Warunkiem usunięcia jest istnienie w liście
dokładnie jednej najdłuższej podlisty rosnącej.
*/
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
void usun(Node*& head) {
	Node* helper = new Node;
	helper->next = head;
	Node* tmp = helper;
	int najwdlugosc = 1;
	Node* najwpoczatek = tmp->next;
	while (tmp->next != NULL) {
		int dlugosc = 1;
		Node* poczatek = tmp->next;
		while (tmp->next->next != NULL && tmp->next->next->value > tmp->next->value) {
			dlugosc++;
			tmp = tmp->next;
		}
		if (dlugosc > najwdlugosc) {
			najwpoczatek = poczatek;
			najwdlugosc = dlugosc;
		}
		 tmp = tmp->next;
	}
	if (najwdlugosc > 1) {
		Node* temp = helper;
		while (temp->next != najwpoczatek) temp = temp->next;
		for (int i = 0; i < najwdlugosc; i++) {
			Node* temp1 = temp->next;
			temp->next = temp->next->next;
			delete temp1;
		}
	}
	head = helper->next;
	delete helper;
}
void add(Node*& head, int val) {
	Node* nowy =new Node;
	nowy->value = val;
	nowy->next = NULL;
	if (head == NULL)  head = nowy;
	else {
		Node* tmp = head;
		while (tmp->next != NULL) tmp = tmp->next;
		tmp->next = nowy;
	}
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head = NULL;
	add(head, 3);
	add(head, 6);
	add(head, 1);
	add(head, 7);
	add(head, 9);
	add(head, 11);
	add(head, 10);
	add(head, 3);
	print(head);
	usun(head);
	print(head);
}