#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "map.h"

// int initialization(void)
// {

// }

Block GameMap[MAP_WIDTH][MAP_LENGTH] = {};

// TODO:控制台控制
// TODO:玩家控制
// TODO:敌人ai

/**
 * @brief 隐藏光标
 *
 */
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};                            // CONSOLE_CURSOR_INFO结构体包含控制台光标的信息,DWORD dwSize光标百分比厚度（1~100）和BOOL bVisible光标是否可见
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); // SetConsoleCursorInfo用来设置指定的控制台光标的大小和可见性。
}

int main(void)
{
    HideCursor();                        // 隐藏光标
    system("mode con cols=50 lines=20"); // 控制窗口大小
    RandomMapGenerate(GameMap);
    PrintMap(GameMap);
    getch();
    return 0;
}