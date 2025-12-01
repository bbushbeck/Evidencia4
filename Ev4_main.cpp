
/* María Fernanda García Bushbeck A01199490
César Tadeo Bernal Sauceda A00841810
Regina Aguilar García A00841923

Fecha: 30/11/2025

Este archivo tiene como finalidad el poder determinar los fan-outs de cada nodo, y
de ahí, poder saber los nodos con mayor fan-out y los posibles botmasters. */

#include <iostream>
#include <fstream>
#include <string>

#include "DefDatos.h"
#include "Graph.h"

using namespace std;

// Asignar un índice a cada IP para poder insertarla en el grafo
// Complejidad O(n)
int assignIndex(string ip, string IPs[], int size){
    for(int i = 0; i < size; i++){
        if(IPs[i] == ip){
            return i;
        }
    }
    return -1; // En caso de no encontrar la IP
}

int main(){
    // Se inicializa el archivo a trabajar así como el número de IPs y aristas
    ifstream archivo("bitacora_EV4.txt");
    string linea;
    int numIPs = 0;
    int numAristas = 0;

    // En caso de que el archivo no pueda ser abierto, se desplegará un mensaje
    if(!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    // Leer la primera línea del archivo
    archivo >> numIPs >> numAristas;

    string IPs[20000];
    for(int i = 0; i < numIPs; i++){
    archivo >> IPs[i];
    }

    Graph GraphIps(numIPs, true);

    for(int i = 0; i < numAristas; i++){
        getline(archivo, linea);

        if(linea.empty()) {   // si hay líneas vacías, ignóralas
            i--;
            continue;
        }

        // Debido a que el archivo contiene las IPs de origen y IPs de destino, se inicializan 
        // las siguientes variables para leer correctamente el archivo txt
        DefDatos datos(linea);
        string ip1 = datos.getIpOrigen();
        string ip2 = datos.getIpDestino();

        int id1 = assignIndex(ip1, IPs, numIPs);
        int id2 = assignIndex(ip2, IPs, numIPs);

        if(id1 == -1 || id2 == -1){
            cout << "IP no encontrada: " << ip1 << " -> " << ip2 << endl;
            continue;
        }

        GraphIps.insertEdge(id1, id2);
    }

    archivo.close();

    // Para obtener el top 5 de nodos con mayor fan-outs, se inicializa el top índice y el top de fan-outs
    const int num = 5;
    int topIdx[num] = {-1, -1, -1, -1, -1};
    int topFan[num] = {-1, -1, -1, -1, -1}; 

    // Determina el fan-out de cada nodo
    for(int i = 0; i < numIPs; i++){
        int fanout = GraphIps.getEdges(i);

        // Nodos que tienen el mayor fan-out se desplegarán en este Top 5
        // Top 5 (descendente) de los nodos con mayores fan-outs
        int pos = 0;
        while(pos < num && !(fanout > topFan[pos])) pos++;
            if(pos < num){
                for(int j = num-1; j > pos; j--){
                    topFan[j] = topFan[j-1];
                    topIdx[j] = topIdx[j-1];
                }
                topFan[pos] = fanout;
                topIdx[pos] = i;
            }
    }

    // Limita la impresión dependiendo de realmente cuantas IPs hayan
    // para evitar errores respecto a la impresión del top 5
    int topNodos;
    if(numIPs < num){
        topNodos = numIPs;
    }else{
        topNodos = num;
    }

    // Se despliega el top 5 de nodos con mayor fan-outs
    cout << "=== TOP 5 NODOS CON MAYOR FAN OUTS (POSIBLES BOTMASTERS) ===" << endl;
    int printed = 0;
    for(int k = 0; k < num && printed < topNodos; k++){
        if(topIdx[k] != -1){
            cout << k+1 << ". " << IPs[topIdx[k]] << " fan-outs: " << topFan[k] << endl;
            printed++;
        }
    } 


    return 0;
}
