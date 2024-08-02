//
// Created by zyc on 2024/8/2.
//
#include "queue.h"
#include <iostream>

void test_queue(){
    {
//        QueueZyc q ;
        QueueZyc *queue = new QueueZyc();
        queue->enqueue(12)->enqueue(34)->enqueue(56)->print();

        {
            int value;
            if (queue->peakFront(&value)) {
                std::cout << "peakFront:" << value << std::endl;
            }
        }

        {
            int value;
            if (queue->peakFront2(value)) {
                std::cout << "peakFront:" << value << std::endl;
            }
        }

        {
            int value;
            if (queue->peakBack(&value)) {
                std::cout << "peakBack:" << value << std::endl;
            }
        }

        {
            int value;
            while (queue->dequeue(&value)) {
                std::cout << "dequeue" << value << std::endl;
            }
        }

        queue->print();
        std::cout << queue->size() << std::endl;

        delete queue;
    }
}