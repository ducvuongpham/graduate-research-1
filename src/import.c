#include "import.h"

int import(Vertex **root, char *fileName)
{

    FILE *filePointer = fopen(fileName, "r+");
    if (filePointer == NULL)
    {
        printf("File error\n");
        return -1;
    }
    if (*root != NULL)
        freeGraph(root);
    *root = NULL;
    char line[200];
    int in, out = 0;
    while (!feof(filePointer))
    {
        fgets(line, 200, filePointer);
        if (line[0] != '#')
        {
            sscanf(line, "%d\t%d\n", &in, &out);
            addVertex(root, in);
            addVertex(root, out);
            addEdge(root, in, out);
        }
    }
    fclose(filePointer);
    return 0;
}
