#include "ccc.h"

int countConnectedComponents(Vertex **root)
{
    int count = 0;

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stackInit(stack);
    spush(stack, *root);
    Vertex *currentVertex;

    while (stack->size != 0)
    {
        currentVertex = spop(stack);
        if (currentVertex->mark == 0)
        {
            depthFirstSearch(currentVertex, NULL);
            count++;
        }

        if (currentVertex->left != NULL)
            spush(stack, currentVertex->left);
        if (currentVertex->right != NULL)
            spush(stack, currentVertex->right);
    }
    freeStack(stack);
    return count;
}

