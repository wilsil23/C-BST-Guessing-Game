// William Diamond - CSE 240
// 1224931045

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "bst.h"

int main()
{
    struct node* root;
    root=create_game_tree();
    char input[30];
    printf("Welcome! Press q to quit or any key to continue:");
    scanf("%s", input);
    if(strcmp(input,"q")==0)
    {
        printf("\nBye Bye!");
    }
    while(strcmp(input,"q")!=0){
        play(&root);
        printf("\nPress q to quit or any key to continue:");
        scanf("%s", input);
        if(strcmp(input,"q")==0){
            printf("Bye Bye!");
        }
    }
}


