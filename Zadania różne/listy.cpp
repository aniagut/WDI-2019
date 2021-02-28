/*
3. Dane są trzy listy jednokierunkowe uporządkowane rosnąco bez powtarzających się
liczb. Proszę napisać funkcję która usunie w każdej liście elementy powtarzające się
w trzech listach. Funkcja ma zwrócić liczbę usuniętych elementów.
*/
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
int usun(Node* head1, Node* head2, Node* head3) {
	Node* helper1 = new Node;
	Node* helper2 = new Node;
	Node* helper3 = new Node;
	helper1->next = head1;
	helper2->next = head2;
	helper3->next = head3;
	Node* tmp1 = helper1;
	Node* tmp2 = helper2;
	Node* tmp3 = helper3;
	int ilosc=0;
	while (tmp1->next != NULL && tmp2->next != NULL && tmp3->next != NULL) {
		while (tmp2->next != NULL && tmp3->next != NULL && tmp2->next->value < tmp1->next->value && tmp3->next->value < tmp1->next->value) {
			tmp2 = tmp2->next;
			tmp3 = tmp3->next;
		}
		if (tmp2->next == NULL && tmp3->next != NULL) {
			while (tmp3->next != NULL && tmp3->next->value < tmp1->next->value) tmp3 = tmp3->next;
			if (tmp3->next != NULL && tmp3->next->value == tmp1->next->value) {
				Node* temp1 = tmp1->next;
				Node* temp3 = tmp3->next;
				tmp1->next = tmp1->next->next;
				tmp3->next = tmp3->next->next;
				delete temp1, temp3;
				ilosc += 2;
			}
			else if (tmp3->next != NULL && tmp3->next->value > tmp1->next->value) tmp1 = tmp1->next;
		}
		else if (tmp3->next == NULL && tmp2->next != NULL) {
			while (tmp2->next != NULL && tmp2->next->value < tmp1->next->value) tmp2 = tmp2->next;
			if (tmp2->next != NULL && tmp2->next->value == tmp1->next->value) {
				Node* temp1 = tmp1->next;
				Node* temp2 = tmp2->next;
				tmp1->next = tmp1->next->next;
				tmp2->next = tmp2->next->next;
				delete temp1, temp2;
				ilosc += 2;
			}
			else if (tmp3->next != NULL && tmp3->next->value > tmp1->next->value) tmp1 = tmp1->next;
		}
		else if (tmp2->next != NULL && tmp3->next != NULL) {
			if (tmp2->next->value == tmp1->next->value) {
				if (tmp3->next->value == tmp1->next->value) {
					Node* temp1 = tmp1->next;
					Node* temp2 = tmp2->next;
					Node* temp3 = tmp3->next;
					tmp1->next = tmp1->next->next;
					tmp2->next = tmp2->next->next;
					tmp3->next = tmp3->next->next;
					delete temp1, temp2, temp3;
					ilosc += 3;
				}
				else {
					Node* temp1 = tmp1->next;
					Node* temp2 = tmp2->next;
					tmp1->next = tmp1->next->next;
					tmp2->next = tmp2->next->next;
					delete temp1, temp2;
					ilosc += 2;
				}
			}
			else if (tmp3->next->value == tmp1->next->value) {
				Node* temp1 = tmp1->next;
				Node* temp3 = tmp3->next;
				tmp1->next = tmp1->next->next;
				tmp3->next = tmp3->next->next;
				delete temp1, temp3;
				ilosc += 2;
			}
			else tmp1 = tmp1->next;
		}
	}
	while (tmp1->next != NULL && tmp2->next != NULL) {
		while (tmp2->next != NULL && tmp2->next->value < tmp1->next->value) tmp2 = tmp2->next;
		if (tmp2->next != NULL && tmp2->next->value == tmp1->next->value) {
			Node* temp1 = tmp1->next;
			Node* temp2 = tmp2->next;
			tmp1->next = tmp1->next->next;
			tmp2->next = tmp2->next->next;
			delete temp1, temp2;
			ilosc += 2;
		}
		else if (tmp2->next != NULL && tmp2->next->value > tmp1->next->value) tmp1 = tmp1->next;
	}
	while (tmp2->next != NULL && tmp3->next != NULL) {
		while (tmp2->next != NULL && tmp2->next->value < tmp3->next->value) tmp2 = tmp2->next;
		if (tmp2->next != NULL && tmp2->next->value == tmp3->next->value) {
			Node* temp3 = tmp3->next;
			Node* temp2 = tmp2->next;
			tmp3->next = tmp3->next->next;
			tmp2->next = tmp2->next->next;
			delete temp3, temp2;
			ilosc += 2;
		}
		else if (tmp2->next != NULL && tmp2->next->value > tmp3->next->value) tmp3 = tmp3->next;
	}
	while (tmp3->next != NULL && tmp1->next != NULL) {
		while (tmp1->next != NULL && tmp1->next->value < tmp3->next->value) tmp1 = tmp1->next;
		if (tmp1->next != NULL && tmp1->next->value == tmp3->next->value) {
			Node* temp3 = tmp3->next;
			Node* temp1 = tmp1->next;
			tmp3->next = tmp3->next->next;
			tmp1->next = tmp1->next->next;
			delete temp3, temp1;
			ilosc += 2;
		}
		else if (tmp1->next != NULL && tmp1->next->value > tmp3->next->value) tmp3 = tmp3->next;
	}
	head1 = helper1->next;
	head2 = helper2->next;
	head3 = helper3->next;
	delete helper1, helper2, helper3;
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
	Node* head3 = NULL;
	add(head1, 1);
	add(head1, 3);
	add(head1, 7);
	add(head1, 11);
	add(head1, 14);
	add(head1, 20);
	add(head1, 31);
	add(head1, 44);
	add(head2, 4);
	add(head2, 7);
	add(head2, 12);
	add(head2, 14);
	add(head2, 21);
	add(head2, 44);
	add(head2, 50);
	add(head3, 2);
	add(head3, 7);
	add(head3, 12);
	add(head3, 24);
	add(head3, 31);
	add(head3, 44);
	add(head3, 51);
	print(head1);
	print(head2);
	print(head3);
	cout << usun(head1, head2, head3) << endl;
	print(head1);
	print(head2);
	print(head3);

}
