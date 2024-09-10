#include <stdio.h>
#include <conio.h>
#include "map.h"
#include "player.h"
#include "console.h"
#include "AI.h"

Block GameMap[MAP_WIDTH][MAP_LENGTH] = {};

// TODO:控制台控制
// TODO:玩家控制
// TODO:敌人ai

Point PlayerPoint;
Point AIPoint[AIMAX];

int main(void)
{
RE:
#ifndef TEST
    initialization();
#endif

    RcursiveMapGenerate(GameMap);

    PlayerPoint = AddPlayer(GameMap, player);
    AIPoint[0] = AddPlayer(GameMap, enemy);
    PrintMap(GameMap);
#ifdef TEST
    PlayerMove(GameMap, &PlayerPoint, UP);
    PlayerMove(GameMap, &PlayerPoint, DOWN);
    PlayerMove(GameMap, &PlayerPoint, LEFT);
    PlayerMove(GameMap, &PlayerPoint, RIGHT);

    PrintMap(GameMap);
#endif

#ifndef TEST
    HANDLE hwnd2 = GetConsoleWindow();
    WindowShake(hwnd2);

    while (TRUE)
    {

        if (KEY_DOWN_FOREGROUND(hwnd2, VK_UP))
        {
            PlayerMove(GameMap, &PlayerPoint, UP);
            PrintMap(GameMap);
        }
        if (KEY_DOWN_FOREGROUND(hwnd2, VK_DOWN))
        {
            PlayerMove(GameMap, &PlayerPoint, DOWN);
            PrintMap(GameMap);
        }
        if (KEY_DOWN_FOREGROUND(hwnd2, VK_LEFT))
        {
            PlayerMove(GameMap, &PlayerPoint, LEFT);
            PrintMap(GameMap);
        }
        if (KEY_DOWN_FOREGROUND(hwnd2, VK_RIGHT))
        {
            PlayerMove(GameMap, &PlayerPoint, RIGHT);
            PrintMap(GameMap);
        }
        if (KEY_DOWN_FOREGROUND(hwnd2, 'R')) // 小写的r不行
        {
            goto RE;
        }
        Sleep(10);
    }
    getch();
#endif
    return 0;
}
