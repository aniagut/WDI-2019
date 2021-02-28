#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
/*
5. Liczby naturalne reprezentowane jak poprzednim zadaniu. Proszę napisać
funkcję dodającą dwie takie liczby. W wyniku dodawania dwóch liczb powinna
powstać nowa lista.
*/


void reverse(Node*& head) {
	Node* tmp = head;
	Node* tmp2 = new Node;
	Node* tmp3 = new Node;
	Node* tmp4 = new Node;
	while (tmp->next != NULL) {
		tmp2 = tmp->next->next;
		tmp3 = tmp->next;
		tmp4 = head;
		head = tmp3;
		head->next = tmp4;
		tmp->next = tmp2;
	}
}

Node* dodawanie(Node*& head1, Node*& head2) {
	Node* head3 =new Node;
	head3->value = -1;
	head3->next = NULL;
	int licznik = 0;
	reverse(head1);
	reverse(head2);
	Node* tmp1 = head1;
	Node* tmp2 = head2;
	Node* tmp3 = head3;
	while (tmp1!= NULL || tmp2!= NULL) {
		int licznik = (tmp1->value + tmp2->value) - ((tmp1->value + tmp2->value) % 10);
		tmp3->value = (tmp1->value + tmp2->value+licznik) % 10;
		licznik = (tmp1->value + tmp2->value) - ((tmp1->value + tmp2->value) % 10);
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		tmp3 = tmp3->next;
	}
	if (tmp1 != NULL && tmp2 == NULL) {
		while (tmp1 != NULL) {
			int licznik1 = (tmp1->value + licznik) - ((tmp1->value + licznik) % 10);
			tmp3->value = (tmp1->value + licznik) % 10;
			tmp1 = tmp1->next;
			tmp3 = tmp3->next;
		}
		tmp3 = NULL;
	}
	else if (tmp2 != NULL && tmp1 == NULL) {
		while (tmp2 != NULL) {
			int licznik2 = (tmp2->value + licznik) - ((tmp2->value + licznik) % 10);
			tmp3->value = (tmp2->value + licznik) % 10;
			tmp2 = tmp2->next;
			tmp3 = tmp3->next;
		}
		tmp3= NULL;
	}
	else {
		tmp3= NULL;
	}
	reverse(head3);
	return head3;
}

void print(Node* head) {
	while (head != NULL) {
		cout << head->value;
		head = head->next;
	}
	cout << endl;
}

int main() {
	Node* head1 = new Node;
	Node* a1 = new Node;
	Node* b1 = new Node;
	Node* c1 = new Node;
	Node* head2 = new Node;
	Node* a2 = new Node;
	Node* b2 = new Node;
	Node* c2 = new Node;
	head1->value = 1;
	head1->next = a1;
	a1->value = 2;
	a1->next = b1;
	b1->value = 3;
	b1->next = c1;
	c1->value = 4;
	c1->next = NULL;
	head2->value = 5;
	head2->next = a2;
	a2->value = 6;
	a2->next = b2;
	b2->value = 7;
	b2->next = c2;
	c2->value = 8;
	c2->next = NULL;
	print(head1);
	print(head2);
	reverse(head1);
	reverse(head2);
	print(head1);
	print(head2);
	print(dodawanie(head1, head2));
} 
