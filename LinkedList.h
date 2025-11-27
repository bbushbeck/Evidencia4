#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class LinkedList {
private:
    Node<T> *head;
    int size;
public:
    LinkedList();
    void addFirst(T valor);
    void addLast(T valor);
    bool addIndex(T valor, int index);
    bool deleteFirst();
    bool deleteLast();
    bool deleteIndex(int index);
    void deleteAll();

    void print();
    int getSize();

    T getData(int index);
    int getIndex(T value);
    bool setAtIndex(T value, int index);
    bool swapData(int index1, int index2);

    ~LinkedList();
    LinkedList(const LinkedList<T> &other);
    LinkedList<T> &operator=(const LinkedList<T> &other);
};

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template <class T>
void LinkedList<T>::addFirst(T valor) {
    Node<T> *newNode = new Node<T>(valor);
    newNode->next = head;
    head = newNode;
    size++;
}

template <class T>
void LinkedList<T>::addLast(T valor) {
    Node<T> *newNode = new Node<T>(valor);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T> *curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    size++;
}

template <class T>
bool LinkedList<T>::addIndex(T valor, int index) {
    if (index < 0 || index > size) {
        return false;
    }
    if (index == 0) {
        addFirst(valor);
        return true;
    } else if (index == size) {
        addLast(valor);
        return true;
    } else {
        Node<T> *newNode = new Node<T>(valor);
        Node<T> *curr = head;
        for (int i = 1; i < index; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
        return true;
    }
}

template <class T>
bool LinkedList<T>::deleteFirst() {
    if (head == nullptr) {
        return false;
    } else {
        Node<T> *del = head;
        head = head->next;
        delete del;
        size--;
        return true;
    }
}

template <class T>
bool LinkedList<T>::deleteLast() {
    if (head == nullptr) {
        return false;
    }
    Node<T> *curr = head;
    if (curr->next == nullptr) {
        delete curr;
        head = nullptr;
    } else {
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        Node<T> *del = curr->next;
        curr->next = nullptr;
        delete del;
    }
    size--;
    return true;
}

template <class T>
bool LinkedList<T>::deleteIndex(int index) {
    if (index < 0 || index >= size) {
        return false;
    }
    if (index == 0) {
        return deleteFirst();
    } else if (index == size - 1) {
        return deleteLast();
    } else {
        Node<T> *curr = head;
        for (int i = 1; i < index; i++) {
            curr = curr->next;
        }
        Node<T> *del = curr->next;
        curr->next = del->next;
        delete del;
        size--;
        return true;
    }
}

template <class T>
void LinkedList<T>::deleteAll() {
    while (head != nullptr) {
        Node<T> *curr = head->next;
        delete head;
        head = curr;
        size--;
    }
}

template <class T>
void LinkedList<T>::print() {
    Node<T> *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

template <class T>
int LinkedList<T>::getSize() {
    return size;
}

template <class T>
LinkedList<T>::~LinkedList() {
    deleteAll();
}

template <class T>
T LinkedList<T>::getData(int index){
    if(index < 0 || index >= size){
        cout << "No existe un elemento con el indice dado" << endl;
        return T();
    } else{
        Node<T> *curr = head;
        for (int i = 0; i < index; i++){
            curr = curr->next;
        }
        return curr->data;
    }
}

template <class T>
int LinkedList<T>::getIndex(T value){
    Node<T> *curr = head;
    for (int i = 0; i < size; i++){
        if(curr->data == value){
            return i;
        }
        curr = curr->next;
    }
    cout << "No existe el elemento" << endl;
    return -1; 
}

template <class T>
bool LinkedList<T>::setAtIndex(T value, int index){
    if(index < 0 || index >= size){
        return false;
    }

    Node<T> *curr = head;
    for (int i = 0; i < index; i++){
        curr = curr->next;
    }
    curr->data = value;
    return true;
}

template <class T>
bool LinkedList<T>::swapData(int index1, int index2){
    if(index1 < 0 || index1 >= size || index2 < 0 || index2 >= size){
        return false;
    }

    Node<T> *curr1 = head;
    Node<T> *curr2 = head;
    for (int i = 0; i < index1; i++){
        curr1 = curr1->next;
    }

    for (int i = 0; i < index2; i++){
        curr2 = curr2->next;
    }

    T actual = curr1->data;
    curr1->data = curr2->data;
    curr2->data = actual;
    return true;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &other){
    head = new Node<T>(other.head->data);
    Node<T> *curr = head;
    Node<T> *otherCurr = other.head->next;
    while(otherCurr != nullptr){
        curr->next = new Node<T>(otherCurr->data);
        curr = curr->next;
        otherCurr = otherCurr->next;
    }
    size = other.size;
}

template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T>&other){
    if(this == &other){
        return *this;
    }
    deleteAll();

    if(other.head == nullptr){
        return *this;
    }

    head = new Node<T>(other.head->data);
    Node<T> *curr = head;
    Node<T> *otherCurr = other.head->next;
    while(otherCurr != nullptr){
        curr->next = new Node<T>(otherCurr->data);
        curr = curr->next;
        otherCurr = otherCurr->next;
    }
    size = other.size

    return *this;
}

#endif