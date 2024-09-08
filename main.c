#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "map.h"
#include "player.h"

Block GameMap[MAP_WIDTH][MAP_LENGTH] = {};

// TODO:控制台控制
// TODO:玩家控制
// TODO:敌人ai

/**
 * @brief 隐藏光标
 *
 */
void HideCursor(); // 隐藏光标
int initialization(void);

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
    getch();

    return 0;
}

int initialization(void)
{
    char chCmd[32];
    sprintf(chCmd, "mode con cols=%d lines=%d", MAP_LENGTH * CHARWHITH, MAP_WIDTH); // 控制窗口大小
    system(chCmd);
    HideCursor();
    return 0;
}

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};                            // CONSOLE_CURSOR_INFO结构体包含控制台光标的信息,DWORD dwSize光标百分比厚度（1~100）和BOOL bVisible光标是否可见
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); // SetConsoleCursorInfo用来设置指定的控制台光标的大小和可见性。
}
