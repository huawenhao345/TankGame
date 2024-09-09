#include <stdio.h>
#include <conio.h>
#include "map.h"
#include "player.h"
#include "console.h"

Block GameMap[MAP_WIDTH][MAP_LENGTH] = {};

// TODO:控制台控制
// TODO:玩家控制
// TODO:敌人a

Point PlayerPoint;

int main(void)
{
#ifndef TEST
    initialization();
#endif

    RcursiveMapGenerate(GameMap);

    PlayerPoint = AddPlayer(GameMap);
    PrintMap(GameMap);
#ifdef TEST
    PlayerMove(GameMap, UP);
    PlayerMove(GameMap, DOWN);
    PlayerMove(GameMap, LEFT);
    PlayerMove(GameMap, RIGHT);
#endif
    PrintMap(GameMap);

    HANDLE hwnd2 = GetConsoleWindow();
    WindowShake(hwnd2);
    getch();

    return 0;
}
