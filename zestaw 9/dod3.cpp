#include <iostream>
using namespace std;
/*
3. Dana jest niepusta lista, proszę napisać funkcję usuwającą co drugi
element listy. Do funkcji należy przekazać wskazanie na pierwszy element
listy.

*/
struct Node {
	int value;
	Node* next;
};

void coDrugi(Node* head) {
	while (head->next != NULL) {
		Node* tmp = head->next;
		if (head->next->next != NULL) {
			head->next = head->next->next;
			delete tmp;
			head = head->next;
		}
		else {
			head->next = NULL;
			delete tmp;
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
	Node* head= new Node;
	Node* pierwszy= new Node;
	Node* drugi= new Node;
	Node* trzeci= new Node;
	Node* czwarty= new Node;
	Node* piaty= new Node;
	Node* szosty= new Node;
	Node* siodmy= new Node;
	Node* osmy= new Node;
	Node* dziewiaty = new Node;
	head->value =0;
	head->next =pierwszy;
	pierwszy->value =1;
	pierwszy->next =drugi;
	drugi->value =2;
	drugi->next =trzeci;
	trzeci->value =3;
	trzeci->next =czwarty;
	czwarty->value =4;
	czwarty->next =piaty;
	piaty->value =5;
	piaty->next =szosty;
	szosty->value =6;
	szosty->next =siodmy;
	siodmy->value =7;
	siodmy->next =osmy;
	osmy->value =8;
	osmy->next =dziewiaty;
	dziewiaty->value = 9;
	dziewiaty->next = NULL;
	print(head);
	coDrugi(head);
	print(head);
}