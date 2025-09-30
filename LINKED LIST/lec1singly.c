//Introduction to LinkedList, learn about struct, and how is node represented
//INSERTIND/DELETING A NODE TRAVERSAL SEARCH AN ELEMENT 
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};

//NODE CREATIION 
struct node* createnode(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory allocation failed ");
        return NULL;
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}
void traversal(struct node* head){
    if(head == NULL){
        printf("LINKED LIST EMPTY ");
        return;
    }
    else{
        struct node* temp = head;
        while(temp!=NULL){
            printf("%d->",temp->data);
            if(temp->next == NULL){
                printf("NULL");
                return;
            }
            temp = temp->next;
        }
    }
    return;
}
//insert 
void insertatbeg(struct node** head,int value){
    struct node* newnode = createnode(value);
    if(newnode == NULL){
        printf("MEMORY ALLOCATION FAILED  ");
        return;
    }
    if(*head == NULL){
        *head = newnode;
        return;
    }else{
        newnode->next = *head;
        *head = newnode;
    }
    return;
}
void insertexceptatend(struct node** head,int value,int postion ){
    struct node* newnode = createnode(value);
    if(newnode == NULL){
        printf("\n Memory allocation failed ");
        return ;
    }
     if(*head == NULL){
        insertatbeg(head,value);
        return;
     }
        struct node* temp = *head;
        for(int i = 1 ;i < postion - 1 && temp->next != NULL ;i ++){
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
        return;

    }

//insertatend
void insertatend(struct node** head,int value){
    struct node* newnode = createnode(value);
    if(newnode == NULL){
        printf("\n Memory allocation failed ");
        return;
    }
    if(*head == NULL){
        insertatbeg(head, value);
    }
    struct node* temp = *head;
    while(temp->next != NULL){
        temp= temp->next;
    }
    temp->next = newnode;
    return;
}
int length(struct node* head){
    struct node* temp = head;
    int length = 0;
    if(head == NULL){
        printf("\n LIST IS EMPTY ");
    }else{
        while(temp != NULL){
            length++;
            if(temp->next == NULL){
                return length;
            }
            temp = temp->next;
        }
    }
    return -1;
}
int searchanelement(struct node* head,int val){
    int pos = 0;
    if(head == NULL){
        printf("\n EMPYT LIST ");
        return -1;
    }else{
        struct node* temp = head;
        while(temp!= NULL){
            pos++;
            if(temp->data == val){
                printf("\n element found at position = %d",pos);
                return pos;
            }
            temp = temp->next;
        }
    }
    printf("\n ELEMENT NOT FOUND");
    return 0;
}
//DELETE 
//deletefrombeg
int deletefrombeg(struct node** head){
    int val;
    if(*head == NULL){
        printf("\n NOTHING TO DELETE LIST IS EMPYT ");
        return 0;
    }else{
        struct node* temp = *head;
        val = temp->data;
        *head = temp->next;
        free(temp);
    }
    return val ;
}
//deletefromend
int deletefromend(struct node** head){
    if(*head == NULL){
        printf("NOTHING TO DELETE \n ");
        return 0;
    }
    else{
        struct node* temp = *head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        int data = temp->data;
        temp->next = NULL;
        return data;
    }
    return 0;
}
int deletefromposition(struct node** head,int pos){
    if(*head == NULL){
        printf("NOTHING TO DELETE ");
        return 0;
    }
    if(pos  == 1){
        int data = deletefrombeg(head);
        return data;
        
    }
   struct node* temp = *head;
   for(int i = 1; i < pos-1 && temp == NULL;i++){
        temp = temp->next;
   }
   if(temp->next ==  NULL || temp == NULL){
     printf("position out of range"); 
   }
   int data = temp->next->data;
   struct node* todel = temp->next;
   temp->next = todel->next;
   free(todel);
   return data;
    
}

int main(){
    struct node* head = NULL;
    printf("element deleted = %d \n ", deletefrombeg(&head));
    insertatbeg(&head,40);
    insertexceptatend(&head,50,2);
    insertexceptatend(&head,40,1);
    insertatend(&head,60);
    traversal(head);
    printf("\n length of the list %d \n",length(head));
    printf("\n Element deleteed from begining  = %d \n ", deletefrombeg(&head));
    traversal(head);
    printf("\n Element deleted = %d",deletefromposition(&head,2));
    printf("\n length of the list %d \n",length(head));
    traversal(head);
    searchanelement(head,40);

    return 0;

}

