#include <iostream>
using namespace std;
/*
4. Dana jest niepusta lista reprezentująca liczbę naturalną. Kolejne
elementy listy przechowują kolejne cyfry. Proszę napisać funkcję
zwiększającą taką liczbę o 1.

*/

struct Node {
	int value;
	Node* next;
}; 

void odwracanie(Node*& head) {
	Node* tmp = head;
	Node* tmp2 = new Node;
	Node* tmp3 = new Node;
	while (tmp->next != NULL) {
		tmp3 = tmp->next->next;
		tmp2 = head;
		head = tmp->next;
		head->next = tmp2;
		tmp->next = tmp3;
	}
}

void plusJeden(Node*& head) {
	odwracanie(head);
	Node* tmp = head;
	if (tmp->value != 9) tmp->value++;
	else {
		while (tmp->value == 9 && tmp->next != NULL) {
			tmp->value = 0;
			tmp = tmp->next;
		}
		if (tmp->value != 9) tmp->value++;
		else {
			tmp->value = 0;
			Node* nowy = new Node;
			nowy->value = 1;
			nowy->next = NULL;
			tmp->next = nowy;
		}
	}
	odwracanie(head);
	
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->value;
		head = head->next;
	}
	cout << endl;
}

int main() {
	Node* head= new Node;
	Node* pierwszy= new Node;
	Node* drugi= new Node;
	Node* trzeci= new Node;
	head->value =8;
	head->next =pierwszy;
	pierwszy->value =7;
	pierwszy->next =drugi;
	drugi->value =9;
	drugi->next =trzeci;
	trzeci->value =9;
	trzeci->next =NULL;
	print(head);
	plusJeden(head);
	print(head);
}