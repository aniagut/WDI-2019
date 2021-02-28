/*
Dany jest zbiór punktów płaszczyzny o współrzędnych będących liczbami całkowitymi.
Zbiór ten dany jest w postaci listy jednokierunkowej.
Proszę napisać funkcję, która rozdziela łańcuch na cztery łańcuchy zawierające punkty należące odpowiednio do I, II, III i IV ćwiartki 
układu współrzędnych, natomiast punkty leżące na osiach układu współrzędnych usuwa z pamięci.
*/
#include <iostream>
using namespace std;
struct Node {
	int x;
	int y;
	Node* next;
};
int rozdzielacz(int x, int y) {
	if (x == 0 || y == 0) return 0;
	if (x > 0 && y > 0) return 1;
	if (x < 0 && y>0) return 2;
	if (x < 0 && y < 0) return 3;
	if (x > 0 && y < 0) return 4;
}
void rozdzielnacwiartki(Node*& head, Node*& cw1, Node*& cw2, Node*& cw3, Node*& cw4) {
	Node* helper = new Node;
	helper->next = head;
	Node *helper1=new Node, *helper2=new Node, *helper3=new Node, *helper4=new Node;
	helper1->next = cw1;
	helper2->next = cw2;
	helper3->next = cw3;
	helper4->next = cw4;
	Node* tmp, * tmp1, * tmp2, * tmp3, * tmp4;
	tmp = helper;
	tmp1 = helper1;
	tmp2 = helper2;
	tmp3 = helper3;
	tmp4 = helper4;
	while (tmp->next != NULL) {
		if (rozdzielacz(tmp->next->x, tmp->next->y) == 0) {
			Node* temp = tmp->next;
			tmp->next = tmp->next->next;
			delete temp;
			tmp = tmp->next;
		}
		else if (rozdzielacz(tmp->next->x, tmp->next->y) == 1) {
			tmp1->next = tmp->next;
			tmp1 = tmp1->next;
			tmp = tmp->next;
		}
		else if (rozdzielacz(tmp->next->x, tmp->next->y) == 2) {
			tmp2->next = tmp->next;
			tmp2 = tmp2->next;
			tmp = tmp->next;
		} 
		else if (rozdzielacz(tmp->next->x, tmp->next->y) == 3) {
			tmp3->next = tmp->next;
			tmp3 = tmp3->next;
			tmp = tmp->next;
		}
		else {
			tmp4->next = tmp->next;
			tmp4 = tmp4->next;
			tmp = tmp->next;
		}
	
	}
	tmp1->next = NULL;
	tmp2->next = NULL;
	tmp3->next = NULL;
	tmp4->next = NULL;
	head = helper->next;
	delete helper;
	cw1 = helper1->next;
	delete helper1;
	cw2 = helper2->next;
	delete helper2;
	cw3 = helper3->next;
	delete helper3;
	cw4 = helper4->next;
	delete helper4;
}
void add(Node*& head, int valuex, int valuey) {
	Node* nowy=new Node;
	nowy->x = valuex;
	nowy->y = valuey;
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
		cout << head->x << "," << head->y << "  ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head = NULL;
	Node* cw1 = NULL;
	Node* cw2 = NULL;
	Node* cw3 = NULL;
	Node* cw4 = NULL;
	add(head, 1, 2);
	add(head, -7, 2);
	add(head, 0, 2);
	add(head, 1, 0);
	add(head, 11, -7);
	add(head, -1, -2);
	add(head, 10, 2);
	add(head, -1, 9);
	print(head);
	rozdzielnacwiartki(head, cw1, cw2, cw3, cw4);
	print(head);
	print(cw1);
	print(cw2);
	print(cw3);
	print(cw4);

}