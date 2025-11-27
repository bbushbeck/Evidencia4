#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T> // Para crear el tipo de variable

class Node{
    public:
        T data;
        Node<T> *next; // Nodo que alberga variables de tipo T
        Node(T valor);

};

template <class T>
Node<T>::Node(T valor){
    data = valor;
    next = nullptr; // En vez de apuntae a basura, apunta a nulo. 
                    //Basura es cuando no sabemos a qué apunta
} 

#endif