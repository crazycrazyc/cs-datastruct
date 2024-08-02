//
// Created by zyc on 2024/8/2.
//

#ifndef LINKLIST_QUEUE_H
#define LINKLIST_QUEUE_H
#include <iostream>

void test_queue();

class QueueZyc{
public:
    struct Node{
        int value;
        Node* next;
    };
public:
    QueueZyc(){
        head_ = nullptr;
        tail_ = nullptr;
    }
    ~QueueZyc(){
        std::cout<< "zyc dead" << std::endl;
        Node* a = head_;
        Node* b = nullptr;
        if(head_ == nullptr){
            return;
        }
        if(head_ == tail_){
            delete head_;
            return;
        }
        while(a->next != nullptr){
            b = a;
            a = a->next;
            delete b;
        }
    }

    QueueZyc* enqueue(int value){
        Node* node = new Node;
        node->value = value;
        node->next = nullptr;
        if(head_ == nullptr){
            head_ = tail_ =  node;
        }else{
            tail_->next = node;
            tail_ = node;
        }
        return this;
    }

    bool dequeue(int * value){
        if(head_ == nullptr) {
            return false;
        }
        if(head_->next != nullptr){
            Node* a = head_;
            head_ = head_->next;
            *value = a->value;
            delete a;
        }else{
            *value = head_->value;
            delete head_;
            head_ = nullptr;
            tail_ = nullptr;
        }
        return true;

    }

    int size(){
        Node* a = head_;
        int i = 0;
        if(head_ == nullptr) {
            return 0;
        }
        if(head_ == tail_){
            return 1;
        }
        while (a != tail_){
            a = a->next;
            i++;
        }
        return i+1;
    }

    void print(){
        Node* a = head_;
        while(a != nullptr) {
            std::cout << a->value << " " ;
            a = a->next;
        }
        std::cout<< std::endl;
    }

    bool peakFront(int *value){
        if(head_ == nullptr){
            return false;
        }
        *value = head_->value;
        return true;
    }

    bool peakBack(int *value){
        if(head_ == nullptr){
            return false;
        }
        *value = tail_->value;
        return true;
    }
    // pointer 指针  &v , int *p
    // c++ reference  引用

    bool peakFront2(int &value){
        if(head_ == nullptr){
            return false;
        }
        value = head_->value;
        return true;
    }
private:
    Node * head_;
    Node * tail_;
};

#endif //LINKLIST_QUEUE_H

