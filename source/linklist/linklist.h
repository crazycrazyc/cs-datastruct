#pragma once


struct Node {
	int value;
	Node* next;
};

struct LinkedList {
	Node* head;
	Node* tail;
};

/// c++ new LinkedList
// c : LinkedList* ll = (LinkedList*) malloc( sizeof( LinkedList)) ;
// ll->head = NULL ;
// ll->tail = NULL;


LinkedList* ll_create();
void ll_add_head(LinkedList* ll, int value);
void ll_add_tail(LinkedList* ll, int value);
void  ll_remove_head(LinkedList* ll);
void  ll_remove_tail(LinkedList* ll);
int ll_size(LinkedList* ll);


void ll_remove(LinkedList* ll, int index);
void ll_remove_value(LinkedList* ll, int value);
void ll_insert(LinkedList* ll, int value, int index);

void ll_test();
void ll_test2();



class LinkedListZyc{
public:
    LinkedListZyc(); // 构造函数   auto ll = new LinkedList() ;  LinkedList ll;
    ~LinkedListZyc(); // 希构函数
    LinkedListZyc* addHead(int value);
    LinkedListZyc* addTail(int value);
    LinkedListZyc* removeHead();
    LinkedListZyc* removeTail();

    int size();
    void print();
private:
    LinkedList * ll_;
protected:

};
