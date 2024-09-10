#include <stdio.h>
#include <windows.h>
#include "player.h"
#include "console.h"

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

WINBOOL MoveWindow2(HWND hwnd, int X, int Y, BOOL bRepaint)
{
    LONG w, h;
    w = GetWindowWidth(hwnd);
    h = GetWindowHeight(hwnd);
    return MoveWindow(hwnd, X, Y, w, h, bRepaint); // 原版函数以像素为单位
}

WINBOOL WindowShake(HWND hwnd)
{
    RECT rt;
    rt = GetWindowRect2(hwnd);
    for (int a = 0; a < 5; a++)
    {
        for (int i = 0; i <= 5; i++)
        {
            Sleep(1);
            MoveWindow2(hwnd, rt.left - i, rt.top, FALSE);
        }
        for (int i = 0; i <= 5; i++)
        {
            Sleep(1);
            MoveWindow2(hwnd, rt.left - 5 + i, rt.top, FALSE);
        }
    }
    return MoveWindow2(hwnd, rt.left, rt.top, TRUE);
}

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
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(hwnd, &cursor_info);

    SetConsoleTitle("TankGame"); // 设置窗口标题
    MoveWindow2(hwnd2,
                GetSystemMetrics(SM_CXFULLSCREEN) / 2 - GetWindowWidth(hwnd2) / 2,
                GetSystemMetrics(SM_CYFULLSCREEN) / 2 - GetWindowHeight(hwnd2) / 2,
                TRUE); // 定位到屏幕中间
    // TODO:搞清楚为什么MoveWindow2用hwnd不起作用

    return 0;
}