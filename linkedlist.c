/*
 * Program to do linked list operations.
 */

#include <stdio.h>
#include <stdlib.h>
struct MyList {
    int data;
    struct MyList *next;
};
int inserToList(int,int,struct MyList**);
void displayList(struct MyList**);
int main()
{
    int cont=1;
    int p, data;
    struct MyList *head;
    head=NULL;
    do {
        printf("\n enter position to insert: ");
        scanf("%d",&p);
        printf("\n enter value to insert: ");
        scanf("%d",&data);
        if(inserToList(data,p,&head)==1)
            printf("\ndone");
        else
            printf("\nfailed");
        printf("\n the List: ");
        displayList(&head);
        printf("\n do you want to continue: ");
        scanf("%d",&cont);
    }while(cont);
}

int inserToList(int data, int p, struct MyList **head){
 
    struct MyList *newNode = (struct MyList *)malloc(sizeof(struct MyList));
    struct MyList *a;
    struct MyList *b;
    newNode->data = data;
    newNode->next = NULL;
    a=*head;
    int k=1;
    if(p == 1 || a == NULL) {
        newNode->next = a;
        *head=newNode;
    }
    else {
        while(a!=NULL && k<p){
            b=a;
            a=a->next;
            k++;
            
        }
        if (a==NULL) {
            b->next = newNode;
            newNode->next = NULL;
        }
        else {
            b->next = newNode;
            newNode->next = a;
        }
    }
    return 1;
}


void displayList(struct MyList **head){
    struct MyList *counter = *head;
    while(counter!=NULL) {
        printf("%d->",counter->data);
        counter=counter->next;
    }
    printf("NULL");
}
