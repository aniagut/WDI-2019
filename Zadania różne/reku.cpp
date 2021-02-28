/*
. Write a recursive function, length, that, given a pointer to a linked list, returns the number of
nodes in the list.
*/

#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
int length(Node* head) {
	if (head == NULL) return 0;
	else {
		return 1 + length(head->next);
	}
}
/*
Write a recursive function, sum, that, given a pointer to a linked list of integers, returns the
sum of the values at the nodes of the list.
*/
int sum(Node* head) {
	if (head == NULL) return 0;
	else {
		return head->value + sum(head->next);
	}
}
/*
14. Write a recursive function that, given a pointer to the head of a linked list of integers,
returns 1 if the list is in ascending order and 0 if it is not.
*/
bool ifAscending(Node* head) {
	if (head->next == NULL) return true;
	if (head->value >= head->next->value) return false;
	else return ifAscending(head->next);
}
void fun(int m, int n) {
	if (n > 0) {
		fun(m - 1, n - 1);
		printf("%d ", m); 
		fun(m + 1, n - 1);
	}
}
int test(int n, int r) { 
	if (r == 0) return 1;
	if (r == 1) return n; 
	if (r == n) return 1;
	return test(n - 1, r - 1) + test(n - 1, r); 
}
/*
Write a recursive function that takes an integer argument and prints the integer with one
space after each digit. For example, given 7583, it prints 7 5 8 3 .
*/
void printt(int n) {
	if (n == 0) return;
	else {
		printt(n / 10);
		cout << n % 10 << " ";
	}
}
int iloscdrog(int Ax, int Ay, int Bx, int By) {
	if (Ax == Bx && Ay == By) return 1;
	else if (Ax > Bx || Ay > By) return 0;
	else return iloscdrog(Ax + 1, Ay, Bx, By) + iloscdrog(Ax, Ay + 1, Bx, By);

}
int main() {
	Node* head = new Node;
	Node* a = new Node;
	Node* b = new Node;
	Node* c = new Node;
	Node* d = new Node;
	head->value = 0;
	head->next = a;
	a->value = 1;
	a->next = b;
	b->value = 2;
	b->next = c;
	c->value = 10;
	c->next = d;
	d->value = 11;
	d->next = NULL;
	cout << iloscdrog(1, 1, 3, 4);
}