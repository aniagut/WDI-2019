#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
/*
30. Proszę napisać funkcję, która usuwa z listy cyklicznej elementy,
których klucz występuje dokładnie k razy. Do funkcji należy przekazać
wskazanie na jeden z elementów listy, oraz liczbę k, funkcja powinna
zwrócić informację czy usunięto jakieś elementy z listy.
*/
void del(Node*& head, int val){
	while (head!=NULL && head->value == val) head = head->next;
		if (head != NULL) {
			Node* tmp = head;
			while (tmp->next != head) {
				if (tmp->next->value == val) {
					Node* temp = tmp->next;
					tmp->next = tmp->next->next;
					delete temp;
				}
				else tmp = tmp->next;
			}
		}

	
}
void usun(Node*& wsk, int key) {
	Node* tmp = wsk;
	while (tmp->next != wsk){
		Node* temp = tmp->next;
		int mykey = tmp->next->value;
		int ile = 1;
		while (temp->next != tmp->next) {
			if (temp->next->value == mykey) {
				ile++;
			}
			temp = temp->next;
		} 
		if (ile == key) {
			del(wsk, mykey);
		}
		tmp = tmp->next;
	}
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
void cykl(Node*& head) {
	Node* tmp = head;
	while (tmp->next != NULL) tmp = tmp->next;
	tmp->next = head;
}
void print(Node* head) {
	Node* tmp = head;
	do {
		cout << head->value << " ";
		head = head->next;
	} while (head!= tmp);
	cout << endl;
}
int main() {
	Node* head = NULL;
	add(head, 3);
	add(head, 7);
	add(head, 4);
	add(head, 3);
	add(head, 4);
	add(head, 5);
	add(head, 9);
	add(head, 9);
	add(head, 13);
	add(head,1);
	add(head, 13);
	add(head, 4);
	add(head, 11);
	add(head, 4);
	add(head, 31);
	add(head, 72);
	cykl(head);
	print(head);
	usun(head, 2);
	print(head);
}