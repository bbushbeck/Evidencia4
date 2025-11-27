#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

#define MAX 8

template <class T>
class Queue {
private:
    T data[MAX];
    int front;
    int rear;
    int size;
public:
    Queue();
    bool enQueue(T value);
    bool deQueue();
    T getFront();
    int getSize();
    bool isEmpty();
    bool isFull();
};

template <class T>
Queue<T>::Queue() {
    front = 0;
    rear = -1;
    size = 0;
}

// O(1)
template <class T>
bool Queue<T>::enQueue(T value) {
    if (isFull()){
        return false;
    }else{
        rear = (rear + 1) % MAX;
        data[rear] = value;
        size++;
        return true;
    }
}

// O(1)
template <class T>
bool Queue<T>::deQueue() {
    if (isEmpty()){
        return false;
    }else{
        front = (front + 1) % MAX;
        size--;
        return true;
    }
}

// O(1)
template <class T>
T Queue<T>::getFront() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return T();
    }else{
        return data[front];
    }
}

// O(1)
template <class T>
int Queue<T>::getSize() {
    return size;
}

// O(1)
template <class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}

// O(1)
template <class T>
bool Queue<T>::isFull() {
    return size == MAX;
}

#endif