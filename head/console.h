#ifndef _CONSOLE_H_
#define _CONSOLE_H_ 1

#include <windows.h>

void HideCursor(); // 隐藏光标
int initialization(void);
WINBOOL MoveWindow2(HWND hwnd, int X, int Y, BOOL bRepaint);

#endif
