#include <time.h>
#include "graph.h"
#include "menu.h"
#include "import.h"
#include "dfs.h"
#include "bfs.h"
#include "ccc.h"

#define output "out"

void option1(Vertex **root)
{
    char fileName[100];
    clearScreen();
    printf("\nImport graph file\n");
    printf("Input file: ");
    scanf("%s%*c", fileName);

    clock_t begin = clock();

    import(root, fileName);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f\n", time_spent);
}

void option2(Vertex **root)
{
    clearScreen();
    printf("\nDepth First Search\n");
    resetMark(*root);

    int start = 0;
    printf("Start vertex: ");
    scanf("%d%*c", &start);

    clock_t begin = clock();

    depthFirstSearch(findNode(*root, start), output);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f\n", time_spent);
}

void option3(Vertex **root)
{
    clearScreen();
    printf("\nBreadth First Search\n");
    resetMark(*root);

    int start = 0;
    printf("Start vertex: ");
    scanf("%d%*c", &start);

    clock_t begin = clock();

    breadthFirstSearch(findNode(*root, start), output);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f\n", time_spent);
}

void option4(Vertex **root)
{
    clearScreen();
    printf("\nCount connected components\n");
    resetMark(*root);

    clock_t begin = clock();
    printf("\nTotal: %d\n", countConnectedComponents(root));
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f\n", time_spent);
}

int main(int argc, char const *argv[])
{
    int option = 0;
    Vertex *root = NULL;

    do
    {
        printMenu();
        scanf("%d%*c", &option);

        switch (option)
        {
        case 1:
            option1(&root);
            getchar();
            break;
        case 2:
            option2(&root);
            getchar();
            break;
        case 3:
            option3(&root);
            getchar();
            break;
        case 4:
            option4(&root);
            getchar();
            break;
        case 5:
            clearScreen();
            freeGraph(&root);
            printf("Exited!\n");
            break;
        case 6:
            printf("Total vertexs: %d\n", countNodes(root));
            getchar();
            break;
        default:
            printf("\nWrong option!! Please choose again");
            getchar();
            break;
        }
    } while (option != 5);

    return 0;
}
