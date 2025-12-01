/* María Fernanda García Bushbeck A01199490
César Tadeo Bernal Sauceda A00841810
Regina Aguilar García A00841923

Fecha: 30/11/2025

Este archivo tiene como finalidad armar la clase Stack para usarla como apoyo en la realización de la clase Graph. */

#ifndef STACK_H
#define STACK_H

#include <iostream>

#define MAX 8

using namespace std;

template <class T>
class Stack{
    private:
        T data[MAX];
        int top;
        int size;
    public:
        Stack();
        bool push(T value);
        bool pop();
        T getTop();
        int getSize();
        bool isEmpty();
        bool isFull();
};

template <class T>
Stack<T>::Stack(){
    top = -1;
    size = 0;
}

// O(1)
template <class T>
bool Stack<T>::push(T value){
    if(isFull()){
        return false;
    }else{
        top++;
        size++;
        data[top] = value;
        return true;
    }
}

// O(1)
template <class T>
bool Stack<T>::pop(){
    if(isEmpty()){
        return false;
    }else{
        top--;
        size--;
        return true;
    }
}

// O(1)
template <class T>
T Stack<T>::getTop(){
    return data[top];
}

// O(1)
template <class T>
int Stack<T>::getSize(){
    return size; // O return top+1
}

// O(1)
template <class T>
bool Stack<T>::isEmpty(){
    if(size == 0){ // O top == -1
        return true;
    }else{
        return false;
    }
}

// O(1)
template <class T>
bool Stack<T>::isFull(){
    if(size == MAX){
        return true;
    }else{
        return false;
    }
}
#endif