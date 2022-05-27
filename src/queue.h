#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "graph.h"
#include "stack.h"

typedef struct _Queue
{
    int size;
    Node *first;
    Node *last;
} Queue;

void queueInit(Queue *queue);
void qpush(Queue *queue, Vertex *vertex);
Vertex *qpop(Queue *queue);
void freeQueue(Queue *queue);

#endif
