/*Zadanie 3.
Dwie listy zawieraj¡ niepowtarzaj¡ce si¦ (w obr¦bie listy) liczby naturalne. W obu listach liczby s¡ posortowane rosn¡co.
Prosz¦ napisa¢ funkcj¦ usuwaj¡c¡ z ka»dej listy liczby wyst¦puj¡ce w drugiej. Do funkcji
nale»y przekaza¢ wskazania na obie listy, funkcja powinna zwróci¢ ª¡czn¡ list¦ usuni¦tych elementów*/

#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
int usun(Node*& head1, Node*& head2) {
	int ilosc = 0;
	Node* helper1 = new Node;
	Node* helper2 = new Node;
	helper1->next = head1;
	helper2->next = head2;
	Node* tmp1 = helper1;
	Node* tmp2 = helper2;
	while (tmp1->next != NULL && tmp2->next!=NULL) {
		while (tmp2->next != NULL && tmp2->next->value < tmp1->next->value) {
			tmp2 = tmp2->next;
		}
		if (tmp2->next != NULL && tmp2->next->value == tmp1->next->value) {
			Node* temp1 = tmp1->next;
			Node* temp2 = tmp2->next;
			tmp1->next = tmp1->next->next;
			tmp2->next = tmp2->next->next;
			delete temp1, temp2;
			ilosc += 2;
		}
		else if (tmp2->next != NULL && tmp2->next->value>tmp1->next->value) tmp1 = tmp1->next;
	}
	head1 = helper1->next;
	head2 = helper2->next;
	delete helper1, helper2;
	return ilosc;
}
void add(Node*& head, int val) {
	Node* nowy = new Node;
	nowy->value = val;
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
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head1 = NULL;
	Node* head2 = NULL;
	add(head1, 2);
	add(head1, 4);
	add(head1, 7);
	add(head1, 12);
	add(head1, 18);
	add(head1, 21);
	add(head1, 25);
	add(head2, 2);
	add(head2, 8);
	add(head2, 12);
	add(head2, 24);
	add(head2, 25);
	print(head1);
	print(head2);
	cout << usun(head1, head2) << endl;
	print(head1);
	print(head2);

}
