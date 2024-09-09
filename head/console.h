#ifndef _CONSOLE_H_
#define _CONSOLE_H_ 1

#include <windows.h>

int initialization(void);
WINBOOL MoveWindow2(HWND hwnd, int X, int Y, BOOL bRepaint);
WINBOOL WindowShake(HWND hwnd);

#endif
