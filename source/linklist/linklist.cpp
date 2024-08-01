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
    Node* last_node = ll->head;
	if (ll->head == nullptr && ll->tail == nullptr) {
		ll->head = node;
		ll->tail = node;
	}else {
        while(last_node->next != nullptr){
            last_node = last_node->next;
        }
        last_node->next = node;
		ll->tail = node;

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
    Node* b = ll->head;
    Node* f = nullptr;
	if (ll->head == nullptr && ll->tail == nullptr) {
		return;
	}
	if (ll->head == ll->tail) {
		delete ll->tail;
		ll->tail = nullptr;
		ll->head = nullptr;
	}
    while(b->next != nullptr){
        f = b;
        b = b->next;
    }
    ll->tail = f;
    f->next = nullptr;
    delete b;
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
    while(c != nullptr) {
        std::cout << c->value << " " ;
        c = c->next;
    }
    std::cout<< std::endl;

}


void ll_test(){
    //std::cout << "ll" << std::endl;
    LinkedList* ll = ll_create();;
    ll_add_head(ll,2);
    ll_add_tail(ll,3);
    ll_add_head(ll,12);
    //ll_print(ll);
    ll_add_tail(ll,21);
    ll_add_tail(ll,36);
//    for(int i = 0;i<10;i++){
//        ll_add_tail(ll,i*4);
//    }
    ll_remove_head(ll);
    ll_remove_tail(ll);
    ll_remove_tail(ll);
    int size = ll_size(ll);
    ll_print(ll);
    std::cout<< size << std::endl;

}


LinkedListZyc::LinkedListZyc(){
    std::cout<< "zyc born.." << std::endl;

    this->ll_ = ll_create();
}

LinkedListZyc::~LinkedListZyc(){
    std::cout<< "zyc dead." << std::endl;
    delete ll_;
}

LinkedListZyc* LinkedListZyc::addHead(int value){
    ll_add_head(this->ll_,value);
    return this;
}

LinkedListZyc* LinkedListZyc::addTail(int value){
    ll_add_tail(ll_,value);
    return this;
}

LinkedListZyc* LinkedListZyc::removeHead() {
    ll_remove_head(ll_);
    return this;
}

LinkedListZyc* LinkedListZyc::removeTail() {
    ll_remove_tail(ll_);
    return this;
}

int LinkedListZyc::size(){
    return ll_size(ll_);

}

void LinkedListZyc::print(){
    ll_print(ll_);
}


void ll_test2(){
    LinkedListZyc ll;
    ll.addHead(10)->addHead(88);
    ll.addTail(11)->addTail(34)->addTail(56);
    ll.print();
    ll.removeHead()->removeHead()->removeTail();
    std::cout<< ll.size() << std::endl;
    ll.print();
}