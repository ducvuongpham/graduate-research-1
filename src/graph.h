#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct _Vertex
{
    unsigned int value;
    void *firstEdge;
    char mark;  // 1 for marked, 0 for not
    char color; // R or B
    struct _Vertex *parent;
    struct _Vertex *left;
    struct _Vertex *right;
} Vertex;

typedef struct _Edge
{
    Vertex *outVertex;
    struct _Edge *nextEdge;
} Edge;

// Function to addVertex new node in RedBlack tree graph
void addVertex(Vertex **root, int value);

// Function to return pointer of a node by it's value
Vertex *findNode(Vertex *root, int value);

void addEdge(Vertex **root, int in, int out);
Edge *findEdge(Vertex *root, int in, int out);
int hasEdge(Vertex *root, int in, int out);

void resetMark(Vertex *root);

int countNodes(Vertex *root);

void freeGraph(Vertex **root);

#endif
