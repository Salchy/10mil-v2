#include <iostream>
#include "rlutil.h"
#include "draw.h"
using namespace std;

void drawGameTitle() {
    system("cls");
    cout << "----------------------------------------------------" << endl;
    cout << "\t _    ___      __  __   ___   _     " << endl;
    cout << "\t/ |  / _ \\    |  \\/  | |_ _| | |    " << endl;
    cout << "\t| | | | | |   | |\\/| |  | |  | |    " << endl;
    cout << "\t| | | |_| |   | |  | |  | |  | |___ " << endl;
    cout << "\t|_|  \\___/    |_|  |_| |___| |_____|" << endl;
    cout << "----------------------------------------------------";
    cout << endl;
}

void drawMenuOptions() {
    cout << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS" << endl;
    cout << endl;
    cout << "-----------------" << endl;
    cout << "0 - SALIR";
    cout << endl;
    cout << "-----------------";
    cout << endl;
}

void showDeveloper() {
    system("cls");
    cout << " ____           _          _             " << endl;
    cout << "/ ___|   __ _  | |   ___  | |__    _   _ " << endl;
    cout << "\\___ \\  / _` | | |  / __| | '_ \\  | | | |" << endl;
    cout << " ___) || (_| | | | | (__  | | | | | |_| |" << endl;
    cout << "|____/  \\__,_| |_|  \\___| |_| |_|  \\__, |" << endl;
    cout << "                                   |___/ " << endl;
    cout << endl;
    system("pause");
}

void showStatistics(string nombrePuntajeMaximo, int puntajeMaximo) {
    drawGameTitle();
    if (puntajeMaximo == 0) {
        cout << "No se han registrado puntajes máximos aún." << endl;
        system("pause");
        return;
    }
    cout << "Jugador con mayor puntaje: " << nombrePuntajeMaximo << "(" << puntajeMaximo << " Puntos)";
    cout << endl;
    system("pause");
}

void drawDados(int dados[]) {
    rlutil::saveDefaultColor();
    for (int i = 0; i < 6; i++) {
        drawDado(dados[i], i);
    }
    rlutil::resetColor();
    system("pause");
}

void drawDado(int numDado, int pos) {
    int initX = 10;
    int initY = 5;
    rlutil::setColor(rlutil::WHITE);
    for (int cursorY = initY; cursorY < initY + 3; cursorY++) {
        rlutil::locate(initX + (6 * pos), cursorY);
        for (int sizeX = 0; sizeX < 5; sizeX++) {
            cout << char(219);
        }
    }
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);

    if (numDado == 1 || numDado == 3 || numDado == 5) {
        rlutil::locate(initX + (6 * pos) + 2, initY + 1);
        cout << '*';
        if (numDado == 1) {
            return;
        }
    }
    rlutil::locate(initX + (6 * pos), initY);
    cout << '*';
    if (numDado >= 2) {
        rlutil::locate(initX + (6 * pos) + 4, initY + 2);
        cout << '*';
    }
    if (numDado >= 4) {
        rlutil::locate(initX + (6 * pos) + 4, initY);
        cout << '*';
        rlutil::locate(initX + (6 * pos), initY + 2);
        cout << '*';
    }
    if (numDado == 6) {
        rlutil::locate(initX + (6 * pos) + 2, initY);
        cout << '*';
        rlutil::locate(initX + (6 * pos) + 2, initY + 2);
        cout << '*';
    }
    rlutil::locate(initX, 15);
    system("pause");
}
