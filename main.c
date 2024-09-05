#include <stdio.h>
#include <windows.h>
#include "map.h"

// int initialization(void)
// {

// }

int main(void)
{
    RandomMapGenerate(GameMap);
    PrintMap(GameMap);

    return 0;
}