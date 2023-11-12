#include "Ejercicio02.h"

Node<char>* Ejercicio02::reverse(Node<char>* prev, Node<char>* next) {
	Node<char>* ultimo = prev->next;
	Node<char>* actual = ultimo->next;
	while (actual != next) {
		ultimo->next = actual->next;
		actual->next = prev->next;
		prev->next = actual;
		actual = ultimo->next;
	}
	return ultimo;
}
Node<char>* Ejercicio02::reverseKGroup(Node<char>* head, int k)
{
	if (head == nullptr) {
		return nullptr;
	}
	else if (k == 1) {
		return head;
	}
	else {
		Node<char>* dummy = new Node<char>{ 0 };
		dummy->next = head;
		Node<char>* prev = dummy;
		Node<char>* actual = head;
		int contador = 0;
		while (actual != nullptr) {
			contador++;
			if (contador % k == 0) {
				prev = reverse(prev, actual->next);
				actual = prev->next;
			}
			else {
				actual = actual->next;
			}
		}
		return dummy->next;
	}
}
