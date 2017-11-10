#ifndef ISVALID_H
#define ISVALID_H
#include "isValid.h"
#endif

#ifndef ARRAYTOOLS_H
#define ARRAYTOOLS_H
#include "arrayTools.h"
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

struct userNode{
  char* username;
  int isPatreon;
  char* patreonName;
  int priorityFactor;
  struct userNode* leftChild;
  struct userNode* rightChild;
};

struct userRoot {
  struct userNode* root;
};

void welcome(){
    printf("Welcome to Commission Selector!\n To begin, please enter the name of your file that holds the \n commissioner information, including the file extension.\n");
}


char* getUserInput(){
    char* file = makeCharArrayOfSize(256);
    int confirm = 0;
    while(confirm == 0){
        printf("Please enter your text name here:\n");
        scanf("%s",file);
        printf("You Entered: %s\nIs this correct? Type 1 for yes, 0 for no.\n",file);
        scanf("%d",&confirm);
    }
    return file;
}


void bstCollect(struct userNode* bstNode,FILE* fp){
  char* temp = makeCharArrayOfSize(256);
  struct userNode* current;
  current = bstNode;
  while(fscanf(fp, temp)){
    printf("What was just read: %s\n",temp);
    if(current->username != NULL){//if current user has a username

    }
    else if(current->username == NULL){//if they dont, lets append
      current->username = makeCharArrayOfSize(strlen(temp));
      strcpy(current->username,temp);
      if(fscanf(fp,temp)){
        current->isPatreon = atoi(temp);
      }
      if(current->isPatreon){
        fscanf(fp,temp);
        current->patreonName = makeCharArrayOfSize(strlen(temp));
        strcpy(current->patreonName,temp);
      }
      fscanf(fp,temp);
      current->priorityFactor = atoi(temp);

    }
  }
}

void makeBst(struct userRoot* bst, FILE* fp){
  bst = (struct userRoot* ) malloc(sizeof(struct userRoot));
  bst->root = (struct userNode*) malloc(sizeof(struct userNode));
  bst->root->leftChild = NULL;
  bst->root->rightChild = NULL;
  bstCollect(bst->root, fp);
}

int main(){
    FILE *fp;
    char* file;
    struct userRoot* bst;
    char read[1];
    read[0] = 'r';//read mode

    welcome();//print welcome message
    file = getUserInput();//get user input for file name
    fp = fopen(file,read);//open file
    if(fp != NULL){//check if file was opened
        printf("We opened file %s\n",file);
    }

    makeBst(bst, fp);

    printf("%s is the name!\n",bst->root->username);

    fclose(fp);
    free(file);
    return 0;
}
