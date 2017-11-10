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


void makeNode(struct userNode* current, int direction){
  //direction, 1 for left, 2 for right
  if(direction == 1){
    current->leftChild = (struct userNode*) malloc(sizeof(struct userNode));
    current->leftChild->leftChild = current->leftChild->rightChild = NULL;
  }
  else if(direction == 2){
    current->rightChild = (struct userNode*) malloc(sizeof(struct userNode));
    current->rightChild->leftChild = current->rightChild->rightChild = NULL;
  }
}

void bstCollect(struct userRoot* bstRoot,FILE* fp){
  char* temp = makeCharArrayOfSize(256);
  struct userNode* current;
  current = bstRoot->root;

    while(fscanf(fp, "%s",temp) != EOF){
      printf("What was just read: %s\n",temp);
      //if current user has a username
      while(current->username != NULL){
        if(*(current->username) > *temp){//if the current node's name is greater
        //than the one in temp, put it in the left child
            if(current->leftChild == NULL){
              //if current's leftchild has not been created
              makeNode(current, 1);

            }
            current = current->leftChild;
        }
        else{
          //if current node's name is lesser than the one in temp
            if(current->rightChild == NULL){
              //if current's right child has not been created
              makeNode(current, 2);
            }
            current = current->rightChild;
        }
      }
      if(current->username == NULL){//if they dont, lets append
        current->username = makeCharArrayOfSize(strlen(temp));
        strcpy(current->username,temp);
        if(fscanf(fp,"%s",temp)){
          current->isPatreon = atoi(temp);
        }
        if(current->isPatreon){
          fscanf(fp,"%s",temp);
          current->patreonName = makeCharArrayOfSize(strlen(temp));
          strcpy(current->patreonName,temp);
        }
        fscanf(fp,"%s",temp);
        current->priorityFactor = atoi(temp);

      }
    }
}



void createBst(struct userRoot* bst, FILE* fp){
  bst = (struct userRoot* ) malloc(sizeof(struct userRoot));
  bst->root = (struct userNode*) malloc(sizeof(struct userNode));
  bst->root->username = NULL;
  bst->root->patreonName = NULL;
  bst->root->leftChild = NULL;
  bst->root->rightChild = NULL;
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

    createBst(bst, fp);
    bstCollect(bst, fp);


    printf("%s is the name!\n",bst->root->username);

    fclose(fp);
    free(file);
    return 0;
}
