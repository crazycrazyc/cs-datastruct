#include <iostream>
#include <memory.h>
#include <stdlib.h>

#include "linklist.h"

LinkedList* ll_create() {
	LinkedList* ll=new LinkedList;
	ll->head = nullptr;
	ll->tail = nullptr;
	return ll;
}

void ll_add_head(LinkedList* ll, int value) {
	Node* node = new Node;
	node->value = value;
	node->next = nullptr;
	if (ll->head == nullptr && ll->tail == nullptr) {
		ll->head = node;
		ll->tail = node;
	}else{
		Node* a = ll->head;
		ll->head = node;
		node->next = a;
	}
	
}

void ll_add_tail(LinkedList* ll, int value) {
	Node* node = new Node;
	node->value = value;
	node->next = nullptr;
	if (ll->head == nullptr && ll->tail == nullptr) {
		ll->head = node;
		ll->tail = node;
	}else {
		ll->tail->next = node;

	}
}

void  ll_remove_head(LinkedList* ll) {
	if (ll->head == nullptr && ll->tail == nullptr) {
		return;
	}
	if (ll->head == ll->tail) {
		delete ll->head;
		ll->head = nullptr;
		ll->tail = nullptr;
	}else {
		Node *b = ll->head->next;
		delete ll->head;
		ll->head = b;
	}
}

void  ll_remove_tail(LinkedList* ll) {
	if (ll->head == nullptr && ll->tail == nullptr) {
		return;
	}
	if (ll->head == ll->tail) {
		delete ll->tail;
		ll->tail = nullptr;
		ll->head = nullptr;
	}
	else {
		Node* b = ll->tail;
		delete ll->tail;
		ll->tail = b;
	}
}

int ll_size(LinkedList* ll) {
	int len = 1;
	Node* c = ll->head;
	if (ll->head == nullptr && ll->tail == nullptr) {
		return 0;
	}
	if (ll->head == ll->tail) {
		return 1;
	}
	for (; c->next != ll->tail;) {
		c = c->next;
		len++;
	}
	return(len+1);
}
 
void ll_print(LinkedList* ll) {
	Node* c = ll->head;
	if (ll->head == nullptr && ll->tail == nullptr) {
		return;
	}
	while (c->next != nullptr) {
		std::cout << c << " " << std::endl;
		c = c->next;
	}
}