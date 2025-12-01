/* María Fernanda García Bushbeck A01199490
César Tadeo Bernal Sauceda A00841810
Regina Aguilar García A00841923

Fecha: 30/11/2025

Este archivo tiene como finalidad armar la clase Graph para usarla en la resolución de la situación problema,
donde se tienen que ver, con un grafo en lista de adyacencia, los nodos con mayor fan-out vía las aristas. */

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

class Graph {
    private:
        int numVertices;
        bool isDirected;
        LinkedList<LinkedList<int> > adjList;
    public:
        Graph(int order, bool isD);
        bool insertEdge(int origin, int dest);
        void insertVertex();
        void print();
        void BFS();
        void DFS();

        // Método para obtener el número de aristas
        int getEdges(int node);
};

// O(n)
Graph::Graph(int order, bool isD){
    numVertices = order;
    isDirected = isD;
    for(int i = 0; i < numVertices; i++){
        LinkedList<int> currList;
        currList.addLast(i);
        adjList.addLast(currList);
    }
}

// O(n)
bool Graph::insertEdge(int origin, int dest){
    if(origin >= numVertices || dest >= numVertices || origin == dest){
        return false;
    }else{
        LinkedList<int> currList;
        if(!isDirected){
            currList = adjList.getData(origin);
            currList.addLast(dest);
            adjList.setAtIndex(currList, origin);
            currList = adjList.getData(dest);
            currList.addLast(origin);
            adjList.setAtIndex(currList, dest);
        }else{
            currList = adjList.getData(origin);
            currList.addLast(dest);
            adjList.setAtIndex(currList, origin);
        }
        return true;
    }
}

// O(1)
void Graph::insertVertex(){
    numVertices++;
    LinkedList<int> currList;
    currList.addLast(numVertices-1);
    adjList.addLast(currList);
}

// O(n + m)
void Graph::print(){
    for(int i = 0; i < numVertices; i++){
        LinkedList<int> currList = adjList.getData(i);
        currList.print();
    }
}

// En las siguientes dos complejidades se toma en cuenta el tamaño del grafo respecto al archivo txt que se está utilizando.
// O(n^3)
void Graph::BFS(){
    int data, neighbor;
    Queue<int> myQueue;
    LinkedList<int> currList;
    bool status[MAX];
    for(int i = 0; i < numVertices; i++){
        status[i] = false;
    }
    for(int i = 0; i < numVertices; i++){
        if(!status[i]){
            myQueue.enQueue(i);
            status[i] = true;
            while(!myQueue.isEmpty()){
                data = myQueue.getFront();
                myQueue.deQueue();
                cout << data << " ";
                currList = adjList.getData(data);
                for(int j = 1; j < currList.getSize(); i++){
                    neighbor = currList.getData(j);
                    if(!status[neighbor]){
                        myQueue.enQueue(neighbor);
                        status[neighbor] = true;
                    }
                }
            }
        }
    }
}

// O(n^3)
void Graph::DFS(){
    Stack<int> myStack;
    LinkedList<int>currList;
    int data, neighbor;
    bool status[numVertices];
    for(int i = 0; i < numVertices; i++){
        status[i] = false;
    }
    for(int i = 0; i < numVertices; i++){
        if(!status[i]){
            myStack.push(i);
            while(!myStack.isEmpty()){
                data = myStack.getTop();
                myStack.pop();
                if(!status[data]){
                    cout << data << " ";
                    status[data] = true;
                    currList = adjList.getData(data);
                    for(int j = currList.getSize()-1; j > 0; j--){
                        neighbor = currList.getData(j);
                        if(!status[neighbor]){
                            myStack.push(neighbor);
                        }
                    }
                }
            }
        }
    }
}

// Método para obtener el número de aristas (Fan-out) de un nodo
// O(1)
int Graph::getEdges(int node){
    if(node < 0 || node >= numVertices){
        cout << "Nodo inválido." << endl;
        return -1;
    }else{
        LinkedList<int> currList = adjList.getData(node);
        return currList.getSize() - 1; // Restar 1 para no contar el nodo mismo
    }
}

#endif