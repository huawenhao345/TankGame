#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "map.h"
#include "player.h"

#define CHARWHITH 2

/**
 * @brief
 * 0 空格
 * 1 砖
 * 2 坦克
 */
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
void GoToxy(int x, int y);

int main(void)
{
    initialization();

    RcursiveMapGenerate(GameMap);

    Point PlayerPoint;

    PlayerPoint = AddPlayer(GameMap);
R:
    PrintMap(GameMap);

    GoToxy(PlayerPoint.x, PlayerPoint.y);

    printf("$$");
    // if (getch() != (int)"q")
    // {
    //     goto R;
    // }

    getch();

    return 0;
}

void GoToxy(int x, int y) // 光标移动函数，X表示横坐标，Y表示纵坐标。
{
    COORD coord;                                // 使用头文件自带的坐标结构,下面的*CHARWHITH是坐标映射
    coord.X = x * CHARWHITH;                    // 这里将int类型值传给short,不过程序中涉及的坐标值均不会超过short范围
    coord.Y = y;                                // y不需要坐标映射
    HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE); // 获得标准输出句柄
    SetConsoleCursorPosition(a, coord);         // 以标准输出的句柄为参数设置控制台光标坐标
}

int initialization(void)
{
    HideCursor();
    system("mode con cols=45 lines=22"); // 控制窗口大小
    return 0;
}

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};                            // CONSOLE_CURSOR_INFO结构体包含控制台光标的信息,DWORD dwSize光标百分比厚度（1~100）和BOOL bVisible光标是否可见
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); // SetConsoleCursorInfo用来设置指定的控制台光标的大小和可见性。
}
