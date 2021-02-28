/*Zad.3 Dany jest zbiór punktów płaszczyzny o współrzędnych będących liczbamicałkowitymi.7bior
ten dany jest w postaci listy jednokierunkowej. Proszę funkcję, która rozdziela łańcuch na cztery
łańcuchy zawierające punkty należące odpowiednio do l,ll,lll i lV ćwiartki układu współrzędnych,
natomiast punkty leżące na osiach układu współrzędnych usuwa z pamięci. Proszę zadeklarować
odpowiednie typy.*/
#include <iostream>
using namespace std;
struct Node {
	int x;
	int y;
	Node* next;
};
void rozdzielanie(Node*& cw1, Node*& cw2, Node*& cw3, Node*& cw4, Node*& lista) {
	Node* helper = new Node;
	helper->next = lista;
	Node* tmp = helper;
	Node* helper1 = new Node;
	Node* helper2 = new Node;
	Node* helper3 = new Node;
	Node* helper4 = new Node;
	helper1->next = cw1;
	helper2->next = cw2;
	helper3->next = cw3;
	helper4->next = cw4;
	Node* tmp1 = helper1;
	Node* tmp2 = helper2;
	Node* tmp3 = helper3;
	Node* tmp4 = helper4;
	while (tmp->next != NULL) {
		if (tmp->next->x == 0 || tmp->next->y == 0) {
			Node* temp = tmp->next;
			tmp->next = tmp->next->next;
			delete temp;
		}
		else if (tmp->next->x > 0 && tmp->next->y > 0) {
			tmp1->next = tmp->next;
			tmp1 = tmp1->next;
			tmp = tmp->next;
		}
		else if (tmp->next->x < 0 && tmp->next->y>0) {
			tmp2->next = tmp->next;
			tmp2 = tmp2->next;
			tmp = tmp->next;
		}
		else if (tmp->next->x < 0 && tmp->next->y < 0) {
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
	lista = helper->next;
	cw1 = helper1->next;
	cw2 = helper2->next;
	cw3 = helper3->next;
	cw4 = helper4->next;
	delete helper, helper1, helper2, helper3, helper4;
}
void add(Node*& head, int valx,int valy) {
	Node* nowy = new Node;
	nowy->x = valx;
	nowy->y = valy;
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
		cout << head->x << "," << head->y << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* lista = NULL;
	Node* cw1 = NULL;
	Node* cw2 = NULL;
	Node* cw3 = NULL;
	Node* cw4 = NULL;
	add(lista, 1, 4);
	add(lista, 1, 7);
	add(lista, -1, 4);
	add(lista, 0, 4);
	add(lista, 1, 0);
	add(lista, -7, -7);
	add(lista, 1, -2);
	add(lista, -2, 4);
	add(lista, 0, 0);
	add(lista, -1, 0);
	add(lista, -3, 3);
	add(lista, -1, -4);
	print(lista);
	rozdzielanie(cw1, cw2, cw3, cw4, lista);
	print(cw1);
	print(cw2);
	print(cw3);
	print(cw4);
	print(lista);

 }