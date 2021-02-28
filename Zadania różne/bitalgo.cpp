#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
	Node* side;
};
Node* dod(Node* head) {
	Node* tmp = head;
	Node* nowa = NULL;
	if (head != NULL) {
		while (tmp->next != NULL || tmp->side != NULL) {
			if (tmp->side != NULL) {
				tmp = tmp->side;
			}
			else tmp = tmp->next;
		}
	}
	return nowa;
}
int del(Node*& head1, Node*& head2) {
	if (head1 == NULL || head2 == NULL) return 0;
	int licznik = 0;
	Node* helper1 = new Node;
	Node* helper2 = new Node;
	int war;
	if (head1->value > head2->value) {
		helper1->next = head2;
		helper2->next= head1;
		war = 1;
	}
	else {
		helper1->next = head1;
		helper2->next = head2;
		war = 2;
	}
	Node* tmp1 = helper1;
	Node* tmp2 = helper2;
	while (tmp1->next != NULL && tmp2->next != NULL) {
		while ( tmp1!=NULL && tmp1->next->value < tmp2->next->value) tmp1 = tmp1->next;
		if (tmp1->next != NULL) {
			if (tmp1->next->value == tmp2->next->value) {
				tmp1->next = tmp1->next->next;
				tmp2->next = tmp2->next->next;
				licznik += 2;
			}
			else tmp2 = tmp2->next;
		}
	}
	if (war == 1) {
		head2 = helper1->next;
		head1 = helper2->next;
		delete helper1, helper2;
	}
	else {
		head1 = helper1->next;
		head2 = helper2->next;
		delete helper1, helper2;
	}
	return licznik;
}
void przep(Node*& head1, Node*& head2) {
	Node* helper1 = new Node;
	Node* helper2 = new Node;
	helper1->next = head1;
	helper2->next = head2;
	Node* tmp2 = helper2;
	while (tmp2->next != NULL) {
		Node* tmp1 = helper1;
		while (tmp1->next != NULL && tmp1->next->value != tmp2->next->value) tmp1 = tmp1->next;
		if (tmp1->next->value == tmp2->next->value) {
			Node* temp = tmp1->next;
			tmp2->next = temp;
			while (tmp2->next != NULL) tmp2 = tmp2->next;
		}
		else tmp2 = tmp2->next;
	}
	head1 = helper1->next;
	head2 = helper2->next;
}
int ile(int n) {
	int licznik = 0;
	while (n > 0) {
		if (n % 8 == 5) licznik++;
		n /= 8;
	}
	return licznik;
}
Node* przenies(Node*& head) {
	Node* tmp = head;
	while (tmp->next != NULL) {
		while (tmp->next != NULL && ile(tmp->next->value) % 2 == 0) tmp = tmp->next;
		if (tmp->next != NULL) {
			Node* temp = tmp->next;
			tmp->next = tmp->next->next;
			temp->next = head;
			head = temp;
		}
	}
	return head;
}

void addFront(Node*& head,int val) {
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
	Node* head = NULL;
	addFront(head, 5);
	addFront(head, 7);
	addFront(head, 7);
	addFront(head, 5);
	addFront(head, 9);
	addFront(head, 5);
	addFront(head, 3);
	addFront(head, 5);
	print(head);
	przenies(head);
	print(head);
}
