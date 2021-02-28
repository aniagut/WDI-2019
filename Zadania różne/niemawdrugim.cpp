/*2. Dane są dwa jednokierunkowe łańcuchy odsyłaczowe (listy) zbudowane z elementów:
 struct node { int w; node* next; };
Każdy łańcuch zawiera niepowtarzające się liczby naturalne. W obu łańcuchach liczby są posortowane rosnąco.
Proszę napisać funkcję usuwającą z każdego łańcucha liczby nie występujące w drugim. Do funkcji należy przekazać
wskazania na oba łańcuchy, funkcja powinna zwrócić łączną liczbę usuniętych elementów*/
#include<iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
int usun(Node*& head1, Node*& head2) {
	int ile = 0;
	Node* helper1 = new Node;
	Node* helper2 = new Node;
	helper1->next = head1;
	helper2->next = head2;
	Node* tmp1 = helper1;
	Node* tmp2 = helper2;
	while (tmp1->next != NULL && tmp2->next!=NULL) {
		while (tmp2->next!=NULL && tmp2->next->value < tmp1->next->value) {
			Node* temp = tmp2->next;
			tmp2->next = tmp2->next->next;
			delete temp;
			ile++;
		}
		while (tmp1->next != NULL && tmp1->next->value < tmp2->next->value) {
			Node* temp = tmp1->next;
			tmp1->next = tmp1->next->next;
			delete temp;
			ile++;
		}
		while (tmp1->next && tmp2->next &&tmp1->next->value == tmp2->next->value) {
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	}
	head1 = helper1->next;
	head2 = helper2->next;
	delete helper1, helper2;
	return ile;
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
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head1 = NULL;
	Node* head2 = NULL;
	add(head1, 1);
	add(head1, 2);
	add(head1, 4);
	add(head1, 6);
	add(head1, 7);
	add(head1, 9);
	add(head1, 10);
	add(head2, 2);
	add(head2, 3);
	add(head2, 5);
	add(head2, 6);
	add(head2, 8);
	add(head2, 9);
	add(head2, 10);
	print(head1);
	print(head2);
	cout << usun(head1, head2) << endl;
	print(head1);
	print(head2);


}