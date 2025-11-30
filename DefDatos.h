/* María Fernanda García Bushbeck A01199490
César Tadeo Bernal Sauceda A00841810
Regina Aguilar García A00841923

Fecha: 30/11/2025

Este archivo tiene como finalidad el facilitar el ordenamiento de IPs. Permite
separar las direcciones IP en sus componentes como manejarlas */

#ifndef DEFDATOS_H
#define DEFDATOS_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class DefDatos {
    private:
        string mes;
        int dia;
        string hora;
        string IP;
        string mensaje;
        int a, b, c, d;
        
        void dividirIP(string ip);

        // Variables de la nueva bitacora
        string ipOrigen;
        string ipDestino;
    public:
        DefDatos() = default;
        DefDatos(string linea);
        DefDatos(string ip, bool soloIP);
        string getIp();
        string toString();
        string getIpOrigen();
        string getIpDestino();
        int convertIPtoInt();
};

// Inicialización de variables
// Complejidad: O(1)
DefDatos::DefDatos(string ip, bool soloIP) {
    IP = ip;
    mensaje = "";
    mes = "";
    hora = "";
    dia = 0;
    dividirIP(ip);
}

// Separación de variables
// Complejidad: O(1)
DefDatos::DefDatos(string linea){
    stringstream ss(linea);
    ss >> mes;
    ss >> dia;
    ss >> hora;
    
    // Leer Ip de origen
    ss >> ipOrigen;

    // Quitar puerto
    string temp;
    stringstream s1(ipOrigen);
    getline(s1, temp, ':');
    ipOrigen = temp;

    // Leer Ip de destino
    ss >> ipDestino;

    // Quitar puerto
    stringstream s2(ipDestino);
    getline(s2, temp, ':');
    ipDestino = temp;

    // Leer el resto del mensaje
    getline(ss, mensaje);
    if(!mensaje.empty() && mensaje[0] == ' '){
        mensaje.erase(0,1);
    }

    dividirIP(ipOrigen);
}

// Dividir la IP en sus componentes
// Complejidad: O(1)
void DefDatos::dividirIP(string ip) {
    stringstream ss(ip);
    char punto;
    ss >> a >> punto >> b >> punto >> c >> punto >> d;
}

// Método para obtener la IP
// Complejidad: O(1)
string DefDatos::getIp() {
    return IP;
}

// Devuelve las IPs como string
// Complejidad: O(1)
string DefDatos::toString() {
    stringstream ss;
    ss << mes << " " << dia << " " << hora << " " << IP << " " << mensaje;
    return ss.str();
}

// Método para obtener la IP de origen
// Complejidad: O(1)
string DefDatos::getIpOrigen() {
    return ipOrigen;
}

// Método para obtener la IP de destino
// Complejidad: O(1)
string DefDatos::getIpDestino() {
    return ipDestino;
}

// Convertir la IP a un entero
// Complejidad: O(1)
int DefDatos::convertIPtoInt() {
    return (a << 24) | (b << 16) | (c << 8) | d;
}

#endif 
