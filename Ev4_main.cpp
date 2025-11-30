#include <iostream>
#include <fstream>
#include <string>

#include "DefDatos.h"
#include "Graph.h"

using namespace std;

// Asignar un índice a cada IP para poder insertarla en el grafo
int assignIndex(string ip, string IPs[], int size){
    for(int i = 0; i < size; i++){
        if(IPs[i] == ip){
            return i;
        }
    }
    return -1; // En caso de no encontrar la IP
}

int main(){
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
    
    for(int i = 0; i < numIPs; i++){
        int fanout = GraphIps.getEdges(i);
        cout << IPs[i] << " tiene fan-out: " << GraphIps.getEdges(i) << endl;
    }

    return 0;
}