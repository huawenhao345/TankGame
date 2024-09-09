#include <stdio.h>
#include <windows.h>
#include "player.h"
#include "console.h"

// TODO:增加窗口抖动效果
// TODO:获取屏幕的大小

int initialization(void)
{
    // 窗口句柄
    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hwnd2 = GetConsoleWindow();

    // 控制窗口大小
    char chCmd[32];
    sprintf(chCmd, "mode con cols=%d lines=%d", MAP_LENGTH * CHARWHITH, MAP_WIDTH); // 这个以字符大小为单位
    system(chCmd);

    // 隐藏光标
    CONSOLE_CURSOR_INFO cursor_info = {1, 0}; // CONSOLE_CURSOR_INFO结构体包含控制台光标的信息,DWORD dwSize光标百分比厚度（1~100）和BOOL bVisible光标是否可见
    SetConsoleCursorInfo(hwnd, &cursor_info); // SetConsoleCursorInfo用来设置指定的控制台光标的大小和可见性。

    SetConsoleTitle("TankGame"); // 设置窗口标题
    MoveWindow2(hwnd2, 500, 500, TRUE);// TODO:搞清楚为什么MoveWindow2(hwnd, 500, 500, TRUE);不起作用

    return 0;
}



RECT GetWindowRect2(HWND hwnd)
{ // 换个名称即可
    RECT rt;
    GetWindowRect(hwnd, &rt); // 这是Windows原版函数
    return rt;
}

LONG GetWindowWidth(HWND hwnd)
{
    RECT rect = GetWindowRect2(hwnd);
    return (rect.right - rect.left);
}

LONG GetWindowHeight(HWND hwnd)
{
    RECT rect = GetWindowRect2(hwnd);
    return (rect.bottom - rect.top);
}

WINBOOL MoveWindow2(HWND hwnd, int X, int Y, BOOL bRepaint) // 2021/07/23 修改此处：删除C语言不支持的bool和默认参数
{
    LONG w, h;
    w = GetWindowWidth(hwnd);
    h = GetWindowHeight(hwnd);
    MoveWindow(hwnd, X, Y, w, h, bRepaint); // 原版函数以像素为单位
}
