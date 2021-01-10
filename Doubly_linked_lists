#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head;

void insert_at_beginning(int n){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        temp->prev=NULL;
        temp->data=n;
        temp->next=NULL;
        head=temp;
    }
    else{
        temp->prev=NULL;
        temp->next=head;
        temp->data=n;
        head=temp;
    }
}


void insert_at_end(int n){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        temp->prev=NULL;
        temp->data=n;
        temp->next=NULL;
        head=temp;
    }
    else{
        struct node* temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
        temp->prev=temp1;
        temp->next=NULL;
        temp->data=n;
    }
}

void insertion_at_nth_pos(int n,int pos){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    if(pos==1){
        if(head==NULL){
            temp->prev=NULL;
            temp->next=NULL;
            temp->data=n;
            head=temp;
        }
        else{
            temp->prev=NULL;
            temp->next=head;
            head=temp;
        }
    }
    else{
        struct node* temp1=head;
        for(int i=0;i<pos-2;i++){
            temp1=temp1->next;
        }
        struct node* p=temp1->next;
        temp->next=temp1->next;
        temp->prev=temp1;
        temp1->next=temp;
        temp->data=n;
        p->prev=temp;
    }
}

void print(){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    head=NULL;
    insert_at_end(10);
    insert_at_beginning(20);
    insert_at_end(30);
    insert_at_end(40);
    insert_at_beginning(90);
    insertion_at_nth_pos(1,3);
    print();
}
