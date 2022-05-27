#include "queue.h"

void queueInit(Queue *queue)
{
    queue->size = 0;
    queue->first = NULL;
    queue->last = NULL;
}

void qpush(Queue *queue, Vertex *vertex)
{

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->vertex = vertex;
    temp->next = NULL;

    if (queue->size == 0)
    {
        queue->first = queue->last = temp;
    }
    else
    {
        queue->last->next = temp;
        queue->last = temp;
    }
    queue->size = queue->size + 1;
}

Vertex *qpop(Queue *queue)
{
    if (queue->size == 0)
        return NULL;
    Vertex *vertex = queue->first->vertex;
    Node *temp = queue->first;
    queue->first = queue->first->next;
    queue->size = queue->size - 1;
    free(temp);
    return vertex;
}

void freeQueue(Queue *queue)
{
    while (queue->first != NULL)
    {
        Node *temp = queue->first;
        queue->first = queue->first->next;
        free(temp);
    }
    if (queue->first != NULL)
        free(queue->first);
    free(queue);
}
