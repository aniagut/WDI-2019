#include <iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
bool find(node* head, int val) {
	while (head != NULL) {
		if (head->data == val) {
			return true;
		}
		else head = head->next;
	}
	return false;
}

void insert(node*& head, int val) {
	node* nowy = new node;
	nowy->data = val;
	if (head != NULL) {
		nowy->next = head;
		head = nowy;
	}
	else {
		head = nowy;
		nowy->next = NULL;
	}
}
void remove(node*& head, int val) {
	if (head == NULL) return;
	node* prev = NULL;
	node* tmp = head;
	if (head->data == val) {
		head = head->next;
		delete head;
	}
	while (tmp->next != NULL && tmp->data != val) {
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp->data == val && tmp->next != NULL) {
		prev->next = tmp->next;
		delete tmp;
	}
	if (tmp->data == val && tmp->next == NULL) {
		prev->next = NULL;
		delete tmp;
	}
}
void wypisuj(node*& head) {
	while (head != NULL) {
		cout << head->data << endl;
		head = head->next;
	}
}
int main() {
	node* head = new node;
	node* pierwszy = new node;
	node* drugi = new node;
	node* trzeci = new node;
	node* czwarty = new node;
	head->data = 7;
	head->next = pierwszy;
	pierwszy->data = 5;
	pierwszy->next = drugi;
	drugi->data = 3;
	drugi->next = trzeci;
	trzeci->data = 17;
	trzeci->next = czwarty;
	czwarty->data = 18;
	czwarty->next = NULL;
	remove(head, 3);
	wypisuj(head);
}