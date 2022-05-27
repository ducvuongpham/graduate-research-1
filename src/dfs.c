#include "dfs.h"

int depthFirstSearch(Vertex *start, char *outputFileName)
{
    if (start == NULL)
        return 0;

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stackInit(stack);

    int count = 0;
    Vertex *currentVertex;
    Edge *edge;

    start->mark = 1;
    spush(stack, start);
    FILE *fp = NULL;
    if (outputFileName == NULL)
        fp = NULL;
    else if (strcmp(outputFileName, "stdout") == 0)
        fp = stdout;
    else
        fp = fopen(outputFileName, "w");

    while (stack->size != 0)
    {
        currentVertex = spop(stack);
        if (fp == stdout)
            printf("Visited %d\n", currentVertex->value);
        else if (fp != NULL && fp != stdout)
            fprintf(fp, "Visited %d\n", currentVertex->value);

        count++;
        edge = currentVertex->firstEdge;
        while (edge != NULL)
        {
            if (edge->outVertex->mark == 0)
            {
                edge->outVertex->mark = 1;
                spush(stack, edge->outVertex);
            }
            edge = edge->nextEdge;
        }
    }
    if (fp != NULL)
    {
        printf("\n\nVertex count: %d\n", count);
        if (fp != stdout)
            fclose(fp);
    }
    freeStack(stack);

    return count;
}


// void DFS(Vertex *start)
// {
//     if (start == NULL)
//         return;
//     start->mark = 1;
//     printf("Visited %d\n", start->value);
//     for (Edge *i = (Edge *)(start->firstEdge); i != NULL; i = i->nextEdge)
//     {
//         if (i->outVertex->mark == 0)
//         {
//             DFS(i->outVertex);
//         }
//     }
// }