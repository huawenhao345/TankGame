#ifndef _AI_H
#define _AI_H 1

#include "map.h"
#define AIMAX 5

typedef struct _node_
{
    Point point;
    struct _node_ *next;
} node, *pnote;

#endif