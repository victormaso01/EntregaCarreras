// Carreritas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "motora.h"
#include <time.h>
#include <Windows.h>

using namespace std;

Motora corredor1(1, 0, "Anuel", "Lambo GokuXVegetta", 0, true, 0);
Motora corredor2(1, 0, "Juan", "El coche", 0, true, 0);
Motora corredor3(1, 0, "Dembele", "La Xavineta", 0, true, 0);
Motora corredor4(1, 0, "Luian", "La Mercedez-Benz", 0, true, 0);
Motora corredor5(1, 0, "Alonso", "Aston Martin 33 ", 0, true, 0);

Motora parrillaArray[5] = { corredor1, corredor2, corredor3, corredor4, corredor5};

Motora jugador1(1, 0, " ", " ", 0, true, 1);
Motora jugador2(1, 0, " ", " ", 0, true, 2);

static void inisio() {
    cout << "===========================================================================" << endl;
    cout << "=                                CARRERONES                               =" << endl;
    cout << "=                                Bienvenido                               =" << endl;
    cout << "===========================================================================" << endl;
}
static void ending() {
    cout << "===========================================================================" << endl;
    cout << "=                                GAME OVER                                =" << endl;
    cout << "=                            Gracias por jugar                            =" << endl;
    cout << "===========================================================================" << endl;
}


static void seleccion(int jugador, Motora &corredor) {
    int selection;
    cout << "Selecciona un personaje:" << endl;
    for (size_t i = 0; i < 5 ; i++)
    {
        cout << i + 1 << ".\t";
        parrillaArray[i].presentation();
    }

    cout << "(Ponga el numero del personaje):" << endl;

    cin >> selection;

    //asignamos los valores del corredor seleccionado al parametro del jugador
    corredor = parrillaArray[selection - 1];

    //asignamos al corredor
    parrillaArray[selection - 1].setSelect(jugador);
    //corredor.presentation();
}

static int numVueltas() {
    int cantidad;
    
    cout << "Indique el numero de rondas (maximo 10)" << endl;
    cin >> cantidad;

    if ((cantidad <= 10)  && (cantidad > 0 )) {
        return cantidad;
    }
    else {
        cout << "Por favor, introduzca un numero valido." << endl;
    }
}

static int numJugadores() {
    int option;
    cout << "Selecciona el modo de juego:" << endl;
    cout << " [1].Jugador contra CPU" << endl;
    cout << " [2].Jugador contra jugador" << endl;
    cin >> option;

    if ((option == 1) || (option ==2)){
        return option;
    }
    
    else {
        cout << "Opcion no valida" << endl;
    }
}

static int dadosJugador() {
    int num = 1 + rand() % (7-1);
    return num;
}

static bool nitro() {
    int bueno;
    bueno = 1 + rand() % (3-1);

    if (bueno == 1) {
        return true;
    }
    else {
        return false;
    }
}

static void nitroTry(int rondas, int conteo, Motora& corredor) {
    int select;
    if (corredor.getTurbo()== true) {

        if ((corredor.getSelec() == 1) || (corredor.getSelec() == 2)) {

            cout << "Quieres gastar tu turbo?" << endl;
            cout << "[1]Si      [2]No" << endl;
            cin >> select;

            if (select == 1) {
                if (nitro()) {
                    cout << "El turbo ha funcionado correctamente." << endl;
                    corredor.setVel(corredor.getVel() * 2);
                    corredor.setTurbo(false);
                    cout << "La velocidad actual de este corredor quedara en " << corredor.getVel() << endl; 
                }
                else if(!nitro()) {
                    cout << "El turbo no ha funcionado correctamente." << endl;
                    corredor.setVel(corredor.getVel() / 2);
                    corredor.setTurbo(false);
                    cout << "La velocidad actual de este corredor quedara en " << corredor.getVel() << endl;
                }
            }
        }
        else {
            if (conteo == rondas - 1) {
                if (nitro()) {
                    cout << "El turbo ha funcionado correctamente." << endl;
                    corredor.setVel(corredor.getVel() * 2);
                    corredor.setTurbo(false);
                    cout << "La velocidad actual de este corredor quedara en " << corredor.getVel() << endl;
                }
                else if (!nitro()) {
                    cout << "El turbo no ha funcionado correctamente." << endl;
                    corredor.setVel(corredor.getVel() / 2);
                    corredor.setTurbo(false);
                    cout << "La velocidad actual de este corredor quedara en " << corredor.getVel() << endl;
                }
            }
        }
    }
    else {
        cout << "Este corredor no dispone de turbo." << endl;
    }
}

static void turno(Motora& corredor) {

    int dados;
    int select;
    string turnoOn;
    if ((corredor.getSelec() == 1) || (corredor.getSelec() == 2)) {
        cout << "Escriba 'DADOS' para lanzar los dados:" << endl;
        cout << "(Si la palabra no esta correctamente escrita, se saltará el turno)" << endl;
        cin >> turnoOn;

        if ((turnoOn == "DADOS") || (turnoOn == "dados")) {
            dados = dadosJugador();
            corredor.setVel(corredor.getVel() + dados);
            cout << "El piloto " << corredor.getPilotName() << " ha sacado un " << dados << ", lo que le permite alcanzar una velocidad de " << corredor.getVel() << endl;

        }
        else {
            cout << "No se ha escrito correctamente, por lo tanto se ha perdido el turno." << endl;
        }

    }
    else {
        dados = dadosJugador();
        corredor.setVel(corredor.getVel() + dados);
        cout << "El piloto " << corredor.getPilotName() << " ha sacado un " << dados << ", lo que le permite alcanzar una velocidad de " << corredor.getVel() << endl;
    }


}

static void distancia(Motora &corredor) {
    corredor.setRec(corredor.getVel() * 100);
}

static void ordenacion(Motora array[]) {
    int i;
    int j;
    Motora aux_elem(1, 0, " ", " ", 0, true, 1);
    int movimientos;
    int elementos = 5;

    for (int i = 0; i < elementos - 1; i++)
    {
        for (j = 1; j < elementos; j++)
        {
            if (array[j].getRec() < array[j - 1].getRec())
            {   // si el elemento anterior es mayor, hacemos el cambio
                aux_elem = array[j];
                array[j] = array[j - 1];
                array[j - 1] = aux_elem;
                
            }
        }
    }
    for (size_t i = 0; i < 5; i++)
    {
        array[i].setPos(5 - i);
        array[i].posicionFinal();
    }
    
}

int main(){
    inisio();
    int cantJugadores = 0;
    
    srand(time(NULL));
    
    cantJugadores = numJugadores();

    cout << "Jugador 1: " << endl;
    
    seleccion(1, jugador1);
    
    jugador1.presentation();

    if (cantJugadores == 2) {

        cout << "Jugador 2:" << endl;
        seleccion(2, jugador2);
        jugador2.presentation();

    }

    int rondas = numVueltas();

    int conteo = 1;
    
    
    while (conteo <= rondas){
        int i = 0;
        while (i < 5) {
            
            cout << "Turno de " << parrillaArray[i].getPilotName() << endl;
            turno(parrillaArray[i]);
            nitroTry(rondas, conteo, parrillaArray[i]);
            i++;
            Sleep(2500);
            cout << " " << endl;
        }

        cout << "Fin de la ronda " << conteo << endl;
        cout << " " << endl;
        conteo++;
        Sleep(2500);
    }
    for (size_t i = 0; i < 5; i++){

        distancia(parrillaArray[i]);

    }
    ordenacion(parrillaArray);

    ending();

}





