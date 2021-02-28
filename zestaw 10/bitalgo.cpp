#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
//5.Odwróć listę jednokierunkową

//rekurencyjne
void reverse_h(Node* current, Node* prev, Node*& head) {
	if (current->next == NULL) {
		current->next = prev;
		head = current;
	}
	else {
		return reverse_h(current->next, current, head);
		current->next = prev;
	}
}
//np. reverse(head, NULL, head);
Node* reverse(Node* head) {
	if (head == NULL) return NULL;
	reverse_h(head, NULL, head);
	return head;
}
//iteracyjnie
Node* reverse_a(Node* head) {
	Node* result = NULL;
	while (head != NULL) {
		Node* tmp = head->next;
		head->next = result;
		head = tmp;
	}
	return;
}
//reku
Node* reverse_r(Node* head, Node* result = NULL) {
	if (head == NULL) return result;
	else {
		Node* tmp = head->next;
		head->next = result;
		result = head;
		head = tmp;
		return reverse_r(head, result);
	}
}
//4.Sprawdź czy lista posiada cykl
//2 wskazniki i jak sie spotkaja to jest cykl
bool czycykl(Node* head) {
	if (head == NULL)return false;
	Node* s_ptr = head;
	Node* f_ptr = head->next;
	while(f_ptr!=NULL && f_ptr->next!=NULL) {
		if (s_ptr == f_ptr) return true;
		s_ptr = s_ptr->next;
		f_ptr = f_ptr->next->next;
	} 
	return false;
}
//stos
//push-wrzucanie na gore
//pop-wyrzucenie z gory
//top-
//isempty()
struct Stos {
	int value;
	Stos* next;
};
bool isEmpty(Stos* s) {
	return s == NULL;
}
int top(Stos* s) {
	if (isEmpty(s)) return -1;
	return s->value;
}
Stos* push(Stos* s, int val) {
	if (isEmpty(s)) return NULL;
	Stos* nowy = new Stos;
	nowy->value = val;
	nowy->next = s;
	return nowy;
}
int pop(Stos*& s) {
	if (isEmpty(s)) return -1;
	else {
		Stos* tmp = s;
		s = s->next;
		int result = tmp->value;
		delete tmp;
		return result;
}

	//kolejka
















