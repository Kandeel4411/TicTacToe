#include <bits/stdc++.h>
#include <windows.h>
#include "TicTacToe.h"
using namespace std;

int main(){

    std::ios::sync_with_stdio(0);

    int exit{1};
    TicTacToe game(exit);
    if(exit == 0) return 0;
    do{

    game.ClearScreen();
    game.viewBoard();
    game.PlayGame(exit);
    if(exit == 0) return 0;
    game.Winner(exit);
    if(exit == 0) return 0;
    }while(game.Again() == 1);



    return 0;
}
