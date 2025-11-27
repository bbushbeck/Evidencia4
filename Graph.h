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
};

Graph::Graph(int order, bool isD){
    numVertices = order;
    isDirected = isD;
    for(int i = 0; i < numVertices; i++){
        LinkedList<int> currList;
        currList.addLast(i);
        adjList.addLast(currList);
    }
}

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

void Graph::insertVertex(){
    numVertices++;
    LinkedList<int> currList;
    currList.addLast(numVertices-1);
    adjList.addLast(currList);
}

void Graph::print(){
    for(int i = 0; i < numVertices; i++){
        LinkedList<int> currList = adjList.getData(i);
        currList.print();
    }
}

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

#endif