#include "N_MY_ARRTR.h"


void ABST::insert(int x)
{
    doInsert(0, x);
}

void ABST::traverse()
{
    traverse(0);
}

void ABST::doInsert(int index, int x)
{
    if (arr[index] == -1)
    {
        arr[index] = x;
        return;
    }
    if (x < arr[index])
    {
        doInsert(2 * index + 1, x);
    }
    else
    {
        doInsert(2 * index + 2, x);
    }
}

void ABST::traverse(int index)
{
    if (arr[2 * index + 1] != -1)
    {
        traverse(2 * index + 1);
    }
    if (arr[2 * index + 2] != -1)
    {
        traverse(2 * index + 2);
    }
}