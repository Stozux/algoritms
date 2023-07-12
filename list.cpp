#include "list.h"
#include <iostream>
using namespace std;

typedef struct list
{
    int maxSize, listSize, curr; int* listArray;
}List;

List* create_list(int size)
{
    List* l = (List*) malloc(sizeof(List));
    l -> maxSize = size;
    l -> listSize = l ->curr = 0;
    l -> listArray = (int*) malloc (size*sizeof(int));
    return l;
}

void insert (List I, int it)
{
    if (I.listSize >= I.maxSize)
    {
        cout << "Error" << "\n";
    }
    int i = I.listSize;
    while (i > I.curr)
    {
        I.listArray[i] = I.listArray[i-1];
        i--;
    }
    I.listArray[I.curr] = it;
    I.listSize++;
}

void moveToStart(List I)
{
    I.curr = 0;
}

void moveToEnd(List I)
{
    I.curr = I.listSize;
}

void prev(List I)
{
    if (I.curr != 0)
    {
        I.curr--;
    }
}

void next(List I)
{
    if (I.curr < I.listSize)
    {
        I.curr++;
    }
}

int remove(List I)
{
    if (I.curr < 0 && I.curr >= I.listSize)
    {
        return NULL;
    }
    int it = I.listArray[I.curr];
    int i = I.curr;
    while(i < I.listSize-1)
    {
        I.listArray[i] = I.listArray[i+1];
        i++;
    }
    I.listSize--;
    return it;
}
















