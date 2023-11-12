#include "Ejercicio03.h"

Node<int>* Ejercicio03::detectCycle(Node<int>* head)
{
	Node<int>* slow = head;
	Node<int>* fast = head;
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			Node<int>* slow2 = head;
			while (slow2 != slow) {
				slow = slow->next;
				slow2 = slow2->next;
			}
			return slow;
		}
	}
	return nullptr;
}
