#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* createnode(int value){
    struct node* newnode = (struct node* )malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory allocation failed ");
        return NULL;
    }else{
        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    return newnode;
}
void traversal(struct node** head){
    if(*head ==  NULL){
        printf("Empty Linked List \n  ");
    }else{
        struct node* temp = *head;
        printf("NULL-->");
        while(temp!=NULL){
            printf("%d<-->",temp->data);
            temp= temp->next;
        }
        printf("NULL");
        return;
    }
}
int  length(struct node* head){
    int length = 0;
    struct node* temp = head;
    if(head == NULL){
        return 0;
    }
    while(temp!= NULL){
        length++;
        if(temp->next == NULL){
            return length;
        }       
         temp = temp->next;
    }
    return 0;
}
void insertatbegin(struct node** head,int value){
    struct node* newnode = createnode(value);
    if(newnode == NULL){
        printf("Memory allocation failed");
        return;
    }
    if(*head == NULL){
        *head = newnode;
        return;
    }else{
        struct node* temp = *head;
        newnode->next = *head;
        (*head)->prev  = newnode;
        *head = newnode;
        return;

    }
}
void insertatend(struct node** head,int value){
    struct node* newnode = createnode(value);
    if(*head == NULL){
        *head = newnode;
        return;
    }
    struct node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return;

}
void deletefrombegining(struct node** head){
    if(*head == NULL){
        printf("\n Empty list Nothing to delete");
        return;
    }
        struct node* temp = *head;
        if(temp->next != NULL){
            *head = temp->next;
            temp->next->prev = NULL;
            free(temp);
            return;
        }else{
            free(temp);
            *head = NULL;
            return;
        }
        return;
        
    }
void deletefromend(struct node** head){
    if(*head == NULL){
        printf("Empty list ");
        return;
    }
    struct node* temp = *head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->prev != NULL){
        temp->prev->next = NULL;
        free(temp);
    }else{
        free(temp);
        *head = NULL;
        return;
    }
    
}
void deletefromposition(struct node** head,int position){
    if(*head == NULL){
        printf("\n List Empty");
    }
    if(position == 1){
        deletefrombegining(head);
        return;
    }
    struct node* temp = *head;
    for(int i = 1;i<position && temp!= NULL;i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Position out of range ");
        return;
    }
    struct node* todelete = temp;
    if(todelete->next != NULL){
        todelete->next->prev = todelete->prev;
    }
    if(todelete->prev!= NULL){
            todelete->prev->next = todelete->next;
    }
    else{
        todelete->prev->next = NULL;
    }
}
void insertatposition(struct node** head,int position,int value){
    struct node* newnode = createnode(value);
    if(*head == NULL && position == 1){
         insertatbegin(*head,value);
         return;
    }else if (*head == NULL && position!= 1)
    {
        printf("Linked list is empty cannot insert at position %d",position);
        return;
    }
    
    if(position == 1){
        insertatbegin(*head,value);
        return;
    }
    struct node* temp = *head;
    for(int i = 1; i<position-1 && temp!=NULL;i++){
        temp= temp->next;
    }
    if(temp->next == NULL){
        temp->next = newnode;
        newnode->prev = temp;
        return;
    }else{
        temp->next->prev = newnode;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
    
    return;

}
int main(){
    struct node* head = NULL;
    length(head) == 0 ? printf("\n Length of the list at begining = 0 \n ") : printf("\n Length of the list = %d \n",length(head));
    insertatend(&head,10);
    insertatbegin(&head,5);
    insertatbegin(&head,0);
    traversal(&head);
    printf("\n Linked List after deletion : " );
    printf("\n deleting one element from front and another from end ");
    deletefrombegining(&head);
    deletefromend(&head);
    traversal(&head);
    insertatend(&head,10);
    insertatbegin(&head,0);
    printf("\n After Inserting again ");
    traversal(&head);
    insertatposition(&head,2,12);
    printf("\n After Inserting again ");
    traversal(&head);
    deletefromposition(&head,2);
    printf("\n After Deleting again ");
    traversal(&head);

    length(head) == 0 ? printf("\n Length of the list at begining  = 0 \n ") : printf("\n Length of the list = %d \n",length(head));
    

}