// William Diamond - CSE 240
// 1224931045

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"

struct node* insert(struct node* root, int data, const char question[], const char guess[])
{
    //---- create new node
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->question = malloc(strlen(question) + 1);
    strcpy(temp->question, question);
    temp->guess = malloc(strlen(guess) + 1);
    strcpy(temp->guess, guess);
    temp->left = temp->right = NULL;
   //--- if tree is empty
   if(root == NULL)
   {
       return temp;
   }

   //---- search for new node's parent
   struct node* current = root;
   struct node* parent = root;
   while(current != NULL)
   {
       parent=current;
       if (data < current->data){
           current=current->left;
       }
       else
       {
           current = current->right;
       }
   }
   //--- insert the node
   if(data < parent->data)
   {
       parent->left = temp;
       
   }
   else
   {
       parent->right = temp;
   }
   return temp;
}

struct node* create_game_tree()
{
    struct node* root = NULL;
    root = insert(root, 100, "Does it grow underground?", "");
    insert(root, 50, "Is it long in shape?", "");
    insert(root, 25, "Is it orange in color?", "");
    insert(root, 15, "", "It's a carrot!");
    insert(root, 35, "", "It's a parsnip!");
    insert(root, 75, "Is it red in color?", "");
    insert(root, 65, "", "It's a radish!");
    insert(root, 85, "", "It's a potato!");
    insert(root, 150, "Does it grow on a tree?", "");
    insert(root, 125, "Is it red in color?", "");
    insert(root, 115, "", "It's an apple!");
    insert(root, 135, "", "It's a peach!");
    insert(root, 175, "Is it red in color?", "");
    insert(root, 165, "", "It's a tomato!");
    insert(root, 185, "", "It's a pea!");
    return root;
}


struct node* search(struct node* root, int data)
{
    struct node* current = root;
    while (current != NULL && data != current->data)
    {
        if (data < current-> data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return current;
}

void play(struct node** root)
{
    struct node* temp = malloc(sizeof(struct node));
    temp = *root;
    bool trueFalse=false;
    char input[30];
    printf("You think of a fruit or vegetable and I will try to guess it!\n");
    while(!trueFalse){
        if(strcmp((temp->question),"") == 0){
            printf(temp->guess);
        }
        else{
            printf(temp->question);
        }
        printf("\ny/n: ");
        scanf("%s",input);
        if((strcmp((temp->question),"") == 0) && (*input=='y')){
            printf("I win!");
            trueFalse=true;
        }
        else if((strcmp((temp->question),"") == 0) && (*input=='n')){
            printf("You win!");
            trueFalse=true;
        }
        else if(*input=='y'){
            temp=temp->left;
        }
        else if(*input=='n'){
            temp=temp->right;
        }
        else{
            printf("Please enter a y or a n");
        }
    }
}
