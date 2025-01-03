#include <iostream>
#include "draw.h"
#include "game.h"
using namespace std;

void initMenu() {
    string nombrePuntajeMaximo;
    int puntajeMaximo;

    char opcion;
    do {
        drawGameTitle();
        drawMenuOptions();
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                //startGame();
                startGame(setGameMode());
                break;
            case '2':
                showStatistics(nombrePuntajeMaximo, puntajeMaximo);
                break;
            case '3':
                showDeveloper();
                break;
            case '0':
                char salir;
                do {
                    system("cls");
                    drawGameTitle();
                    cout << "¿Seguro que deseas salir? (S/N): ";
                    cin >> salir;

                    if (isYes(salir)) {
                        opcion = 0;
                    } else if (!yesOrNo(salir)) {
                        cout << "Opción invalida, intente nuevamente.";
                        cout << endl;
                        system("pause");
                    }
                } while (!yesOrNo(salir));
                break;
            default:
                cout << "Opción invalida, intente nuevamente.";
                cout << endl;
                system("pause");
                break;
        }
    } while (opcion != 0);
}

void startGame(int gameMode) {
    string playerName1, playerName2;
    if (gameMode == 1) {
        string randomNames[10] = {"Jorge", "Alicia", "Silvia", "Ana", "Luis", "Susana", "Hector", "Pedro", "Juan", "Marta"};
        char confirmar;
        do {
            drawGameTitle();
            cout << endl;

            cout << "Ingrese el nombre del jugador 1: ";
            cin >> playerName1;

            cout << "¿Confirmar nombre? (S/N): ";
            cin >> confirmar;
            if (!yesOrNo(confirmar)) {
                cout << "Opcion invalida. Intente nuevamente.";
                cout << endl;
                system("pause");
            }
        } while (!isYes(confirmar));
        do {
            playerName2 = randomNames[numeroRandom(0, 9)];
        } while (playerName2 == playerName1);
    } else if (gameMode == 2) {
        registerPlayerNames(playerName1, playerName2);
    }
    game();
}

void game() {
    bool turno = true;
    // True = Turno jugador 1
    // False = Turno jugador 2
    while (true) {
        draw

        turno = !turno;
        if (ganador) {
            break;
        }
    }
    // mostrarGanador();
}

int setGameMode() {
    char opcion;
    do {
        drawGameTitle();
        cout << endl;

        cout << "1 - Modo 1 jugador" << endl;
        cout << "2 - Modo 2 jugadores" << endl;
        cout << "0 - Cancelar" << endl << endl;
        cout << "Seleccione el modo de juego (1/2): ";
        cin >> opcion;
        if (opcion == 48) {
            return 0;
        }
        if (opcion == 49 || opcion == 50) {
            if (opcion == 49) {
                return 1;
            } else {
                return 2;
            }
        } else {
            cout << "Opcion incorrecta, Intente nuevamente.";
            system("pause");
        }
    } while (opcion != 49 && opcion != 50);
    return opcion;
}

void registerPlayerNames(string &player1, string &player2) {
    char confirmar;
    do {
        drawGameTitle();
        cout << endl;
        cout << "Ingrese el nombre del jugador 1: ";
        cin >> player1;
        cout << "Ingrese el nombre del jugador 2: ";
        cin >> player2;

        cout << "¿Confirmar nombres? (S/N): ";
        cin >> confirmar;
        if (!yesOrNo(confirmar)) {
            cout << "Opcion invalida. Intente nuevamente.";
            cout << endl;
            system("pause");
        }
    } while (!isYes(confirmar));
}

int numeroRandom(int minimo, int maximo) {
    return (rand() % (maximo - minimo + 1)) + minimo;
}

bool yesOrNo(char option) {
    return (option == 83 || option == 115 || option == 78 || option == 110);
}

bool isYes(char option){
    return (option == 83 || option == 115);
}

bool isNo(char option) {
    return (option == 78 || option == 110);
}
