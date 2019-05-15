/*
 * Program to do linked list operations.
 */

#include <stdio.h>
#include <stdlib.h>
struct MyList {
    int data;
    struct MyList *next;
};
int carry=0;
int length_of_first=0, length_of_second=0, diff=0;
int inserToList(int,int,struct MyList**);
void displayList(struct MyList**);
struct MyList* reverseList(struct MyList*);
struct MyList* sumOfList(struct MyList*, struct MyList*);
int getDiff(struct MyList*, struct MyList*);
int main()
{
    int cont=1;
    int p, data;
    struct MyList *head,*head2,*head1;
    head=NULL,head2=NULL,head1=NULL;
    
    //entering data to list
    // do {
    //     printf("\n enter position to insert: ");
    //     scanf("%d",&p);
    //     printf("\n enter value to insert: ");
    //     scanf("%d",&data);
    //     if(inserToList(data,p,&head)==1)
    //         printf("\ndone");
    //     else
    //         printf("\nfailed");
    //     printf("\n the List: ");
    //     displayList(&head);
    //     printf("\n do you want to continue: ");
    //     scanf("%d",&cont);
    // }while(cont);
    // head = reverseList(head);
    // displayList(&head);
    // free(head);
    
    inserToList(1,1,&head1);
    inserToList(2,2,&head1);
    displayList(&head1);
    
    //create another list
    inserToList(1,1,&head2);
    inserToList(2,2,&head2);
    inserToList(3,3,&head2);
    displayList(&head2);
    
    //sum of two linked list having same size
    diff = getDiff(head1,head2);
    struct MyList* sum;
    if(length_of_first>length_of_second) {
        sum = sumOfList(head1,head2);
    }
    else{
        sum = sumOfList(head2,head1);
    }
    printf("\nsum :");
    displayList(&sum);
}
int getDiff(struct MyList *head1, struct MyList *head2){
    while(head1!=NULL) {
        length_of_first++;
        head1=head1->next;
    }
    while(head2!=NULL){
        length_of_second++;
        head2=head2->next;
    }
    if(length_of_first>length_of_second){
        return length_of_first-length_of_second;
    }
    else{
        return length_of_second-length_of_first;
    }
}

struct MyList* sumOfList(struct MyList *head1, struct MyList *head2) {
    if(head2 == NULL) {
        return head1;
    }
    else if(head1 == NULL){
        return NULL;
    }
    struct MyList *temp=(struct MyList*)malloc(sizeof(struct MyList));
    if(diff > 0) {
        temp=head1;
        diff--;
        temp->next = sumOfList(head1->next, head2);
        return temp;
    }
    int sum=0;
    sum = sum + head1->data + head2->data;
    carry=sum/10;
    temp->data=sum%10;
    if(head1->next == NULL && head2->next == NULL) {
        temp->next=NULL;
        return temp;
    }
    temp->next = sumOfList(head1->next, head2->next);
    return temp;
    
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

struct MyList* reverseList(struct MyList *head) {
    struct MyList *temp=NULL,*nextNode;
    while(head!=NULL) {
        nextNode = head->next;
        head->next=temp;
        temp=head;
        head=nextNode;
    }
    return temp;
}

void displayList(struct MyList **head){
    printf("\n");
    struct MyList *counter = *head;
    while(counter!=NULL) {
        printf("%d->",counter->data);
        counter=counter->next;
    }
    printf("NULL");
}
