// William Diamond - CSE 240
// 1224931045

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#define bst.h
struct node
{
    int data;
    char* question;
    char* guess;
    struct node* left;
    struct node* right;
};
struct node* create_game_tree();
void play(struct node** root);