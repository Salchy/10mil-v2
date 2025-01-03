#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

void initMenu();

void startGame(int gameMode);

void registerPlayerNames(std::string &player1, std::string &player2);

int setGameMode();

int numeroRandom(int minimo, int maximo);

bool yesOrNo(char option);

bool isYes(char option);

bool isNo(char option);
#endif // GAME_H_INCLUDED
