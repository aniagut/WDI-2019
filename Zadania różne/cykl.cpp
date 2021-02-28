#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
bool warunek1(int n) {
	int ilosc = 0;
	while (n > 0) {
		ilosc++;
		n /= 7;
	}
	if (ilosc <= 7) return true;
	else return false;
}
bool warunek2(int n) {
	if (n % 2 == 0 || n % 3 == 0) return true;
	else return false;
}
void reverse(Node*& head) {
	if (head != NULL) {
		Node* tmp = head;
		Node* tmp1 = new Node;
		while (tmp->next) {
			tmp1 = tmp->next;
			tmp->next = tmp->next->next;
			tmp1->next = head;
			head = tmp1;
		}
	}
}
void rozdziel(Node* head, Node*& war1, Node*& war2) {
	Node* tmp1 = war1;
	Node* tmp2 = war2;
	while (head) {
		if (warunek1(head->value)) {
			tmp1->next = head;
			tmp1 = tmp1->next;
		}
		if (warunek2(head->value)) {
			tmp2->next = head;
			tmp2 = tmp2->next;
		}
		head = head->next;
}
	tmp1->next = NULL;
	tmp2->next = NULL;
	war1 = war1->next;
	war2 = war2->next;
	if (war1 != NULL) {
		if (war1->next == NULL) war1->next = war1;
		else {
			Node* temp1 = war1;
			while (temp1->next)  temp1 = temp1->next;
			temp1->next = war1;
		}
	}
	if (war2 != NULL) {
		if (war2->next == NULL);
		else {
			reverse(war2);
			Node* temp2 = war2;
			while (temp2->next) temp2 = temp2->next;
			temp2->next = war2;
		}
	}
}
void add(Node*& head, int val) {
	Node* nowy = new Node;
		nowy->value = val;
	nowy->next = NULL;
		if (head == NULL) head = nowy;
		else {
			Node* tmp = head;
			while (tmp->next) tmp = tmp->next;
			tmp->next = nowy;
		}
}
void dodajcykl(Node*& head) {
	if (head != NULL) {
		Node* tmp = head;
		while (tmp->next) tmp = tmp->next;
		tmp->next = head;
	}
}
void printcykl(Node* wsk) {
	Node* tmp = wsk;
	do {
		cout << tmp->value<< " ";
		tmp = tmp->next;
	} while (tmp != wsk);
}
int main() {
	Node* head = NULL;
	add(head, 2434723);
	add(head, 16);
	add(head, 375965652);
	add(head, 439735);
	add(head, 496325964);
	add(head, 15);
	add(head, 18);
	add(head, 243204941);
	dodajcykl(head);
	printcykl(head);
	Node* war1 = new Node;
	Node* war2 = new Node;
	war1->next = NULL;
	war2->next = NULL;
	rozdziel(head, war1, war2);
	printcykl(war1);
	printcykl(war2);
}