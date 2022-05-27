#include "bfs.h"

int breadthFirstSearch(Vertex *start, char *outputFileName)
{
    if (start == NULL)
        return 0;

    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queueInit(queue);

    int count = 0;
    Vertex *currentVertex;
    Edge *edge;

    start->mark = 1;
    qpush(queue, start);
    FILE *fp = NULL;
    if (outputFileName == NULL)
        fp = NULL;
    else if (strcmp(outputFileName, "stdout") == 0)
        fp = stdout;
    else
        fp = fopen(outputFileName, "w");

    while (queue->size != 0)
    {
        currentVertex = qpop(queue);
        if (fp != NULL)
            fprintf(fp, "Visited %d\n", currentVertex->value);

        count++;
        edge = currentVertex->firstEdge;
        while (edge != NULL)
        {
            if (edge->outVertex->mark == 0)
            {
                edge->outVertex->mark = 1;
                qpush(queue, edge->outVertex);
            }
            edge = edge->nextEdge;
        }
    }
    if (fp != NULL)
    {
        printf("\n\nVertex count: %d\n", count);
        if(fp != stdout)
        fclose(fp);
    }
    freeQueue(queue);
    return count;
}