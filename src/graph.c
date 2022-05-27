#include "graph.h"

void leftRotate(Vertex **root, Vertex *temp)
{
    Vertex *right = temp->right;
    temp->right = right->left;
    if (temp->right != NULL)
        temp->right->parent = temp;
    right->parent = temp->parent;
    if (temp->parent == NULL)
        (*root) = right;
    else if (temp == temp->parent->left)
        temp->parent->left = right;
    else
        temp->parent->right = right;
    right->left = temp;
    temp->parent = right;
}

void rightRotate(Vertex **root, Vertex *temp)
{
    Vertex *left = temp->left;
    temp->left = left->right;
    if (temp->left != NULL)
        temp->left->parent = temp;
    left->parent = temp->parent;
    if (temp->parent == NULL)
        (*root) = left;
    else if (temp == temp->parent->left)
        temp->parent->left = left;
    else
        temp->parent->right = left;
    left->right = temp;
    temp->parent = left;
}

// fix the red-black tree
void fixup(Vertex **root, Vertex *temp)
{
    Vertex *uncle, *parent, *grandParent;

    while ((temp != *root) && (temp->parent->color == 'R'))
    {
        parent = temp->parent;
        grandParent = parent->parent;
        if (parent == grandParent->right)
        {
            uncle = grandParent->left;
            if (uncle != NULL && uncle->color == 'R')
            {
                uncle->color = 'B';
                parent->color = 'B';
                grandParent->color = 'R';
                temp = grandParent;
            }
            else
            {
                if (temp == parent->left)
                {
                    temp = parent;
                    rightRotate(root, temp);
                    parent = temp->parent;
                    grandParent = parent->parent;
                }
                parent->color = 'B';
                grandParent->color = 'R';
                leftRotate(root, grandParent);
            }
        }
        else
        {
            uncle = grandParent->right;
            if (uncle != NULL && uncle->color == 'R')
            {
                uncle->color = 'B';
                parent->color = 'B';
                grandParent->color = 'R';
                temp = grandParent;
            }
            else
            {
                if (temp == parent->right)
                {
                    temp = parent;
                    leftRotate(root, temp);
                    parent = temp->parent;
                    grandParent = parent->parent;
                }
                parent->color = 'B';
                grandParent->color = 'R';
                rightRotate(root, grandParent);
            }
        }
    }
    (*root)->color = 'B';
}

void addVertex(Vertex **root, int value)
{
    if (findNode(*root, value) != NULL)
        return;
    Vertex *temp = (Vertex *)malloc(sizeof(Vertex));
    temp->value = value;
    temp->left = temp->right = temp->parent = temp->firstEdge = NULL;

    if (*root == NULL)
    {
        temp->color = 'B';
        (*root) = temp;
    }
    else
    {
        Vertex *y = NULL;
        Vertex *x = (*root);

        // Follow standard BST addVertex steps to first addVertex the node
        while (x != NULL)
        {
            y = x;
            if (temp->value < x->value)
                x = x->left;
            else
                x = x->right;
        }
        temp->parent = y;
        if (temp->value > y->value)
            y->right = temp;
        else if (temp->value < y->value)
            y->left = temp;
        else
        {
            free(temp);
            return;
        }
        temp->color = 'R';

        // Fix reb-black tree's property if it's voilated due to insertion.
        fixup(root, temp);
    }
}

Vertex *findNode(Vertex *root, int value)
{
    if (root == NULL || root->value == value)
        return root;
    else if (root->value > value)
        return findNode(root->left, value);
    else
        return findNode(root->right, value);
}

void addEdge(Vertex **root, int in, int out)
{
    if (findEdge(*root, in, out) != NULL)
        return;

    Vertex *inNode = findNode(*root, in);
    Vertex *outNode = findNode(*root, out);

    if (inNode == NULL || outNode == NULL)
        return;

    Edge *rootEdge = ((Edge *)inNode->firstEdge);
    if (inNode->firstEdge == NULL)
    {
        inNode->firstEdge = (Edge *)malloc(sizeof(Edge));
        ((Edge *)inNode->firstEdge)->outVertex = outNode;
        ((Edge *)inNode->firstEdge)->nextEdge = NULL;
    }
    else if (rootEdge->outVertex->value > out)
    {
        Edge *tempEdge = (Edge *)malloc(sizeof(Edge));
        tempEdge->outVertex = outNode;
        tempEdge->nextEdge = rootEdge->nextEdge;
        inNode->firstEdge = tempEdge;
    }
    else
    {
        Edge *first = rootEdge->nextEdge;
        Edge *second = rootEdge;
        while (first != NULL && first->outVertex->value < out)
        {
            second = first;
            first = first->nextEdge;
        }

        Edge *tempEdge = (Edge *)malloc(sizeof(Edge));
        tempEdge->outVertex = outNode;
        tempEdge->nextEdge = first;
        second->nextEdge = tempEdge;
    }
}

Edge *findEdge(Vertex *root, int in, int out)
{
    Vertex *inNode = findNode(root, in);
    if (inNode == NULL)
        return NULL;

    Edge *temp = inNode->firstEdge;
    while (temp != NULL && temp->outVertex->value != out)
        temp = temp->nextEdge;
    return temp;
}

int hasEdge(Vertex *root, int in, int out)
{
    if (findEdge(root, in, out) != NULL)
        return 1;
    else
        return 0;
}

void resetMark(Vertex *root)
{
    if (root == NULL)
        return;
    resetMark(root->left);
    resetMark(root->right);
    root->mark = 0;
}

int countNodes(Vertex *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void freeEdges(Edge *firstEdge)
{
    if (firstEdge == NULL)
        return;
    freeEdges(firstEdge->nextEdge);
    free(firstEdge);
}

void freeAllVertexs(Vertex *root)
{
    if (root == NULL)
        return;
    freeAllVertexs(root->left);
    freeAllVertexs(root->right);
    freeEdges(root->firstEdge);
    free(root);
}

void freeGraph(Vertex **root)
{
    freeAllVertexs(*root);
    *root = NULL;
}
