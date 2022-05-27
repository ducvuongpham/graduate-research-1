#include "menu.h"
void clearScreen()
{
    system("clear");
}

void printMenu()
{
    clearScreen();
    printf("Graduate research 1 program\n\n");
    printf("1. Import graph file\n");
    printf("2. Depth First Search\n");
    printf("3. Breadth First Search\n");
    printf("4. Count connected components\n");
    printf("5. Quit\n");
    printf("-----------------------------------------------------\n");
    printf("Please chosse a option:\t");
} 