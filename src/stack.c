#include "stack.h"

void stackInit(Stack *stack)
{
    stack->size = 0;
    stack->first = NULL;
}

void spush(Stack *stack, Vertex *vertex)
{

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->vertex = vertex;
    temp->next = NULL;

    if (stack->size == 0)
    {
        stack->first = temp;
    }
    else
    {
        temp->next = stack->first;
        stack->first = temp;
    }
    stack->size = stack->size + 1;
}

Vertex *spop(Stack *stack)
{
    if (stack->size == 0)
        return NULL;
    Vertex *vertex = stack->first->vertex;
    Node *temp = stack->first;
    stack->first = stack->first->next;
    stack->size = stack->size - 1;
    free(temp);
    return vertex;
}

Vertex *stop(Stack *stack)
{
    if (stack->size == 0)
        return NULL;
    stack->size = stack->size - 1;
    return stack->first->vertex;
}

void freeStack(Stack *stack)
{
    while (stack->first != NULL)
    {
        Node *temp = stack->first;
        stack->first = stack->first->next;
        free(temp);
    }
    free(stack);
}