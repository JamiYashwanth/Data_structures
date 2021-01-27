#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head;

void insert_node_at_end(int n){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->next=NULL;
    if(head!=NULL){
        struct node* temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
    else{
        head=temp;
    }
}


void insert_node_at_beginning(int n){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->next=NULL;
    if(head!=NULL){
        temp->next=head;
        head=temp;
    }
    else{
        head=temp;
    }
}


void insert(int n,int pos){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->next=NULL;
    if(pos==1){
        if(head==NULL){
            head=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
    }
    else{
        struct node* temp1=head;
        for(int i=0;i<pos-2;i++){
            temp1=temp1->next;
        }
        struct node* k=temp1->next;
        temp1->next=temp;
        temp->next=k;
    }
}

void del_pos(int pos){
    if(pos==1){
		struct node* temp=head;
		head=temp->next;
		free(temp);
	}
	else{
		struct node* temp=head;
		for(int i=0;i<pos-2;i++){
			temp=temp->next;
		}
		struct node* temp1=head;
		for(int i=0;i<pos-1;i++){
			temp1=temp1->next;
		}
		temp->next=temp1->next;
		free(temp1);
	}
}

void reverse_linked_list(){
	struct node* temp=head;
	struct node* prev=NULL;
	while(temp!=NULL){
		struct node* k=temp->next;
		temp->next=prev;
		prev=temp;
		temp=k;
	}
	head=prev;
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
        insert(2,1);						//inserting at nth position
        insert(3,2);						//inserting at nth position
        insert(4,3);						//inserting at nth position
        insert(5,4);						//inserting at nth position
        insert(10,1);						//inserting at nth position
        print();						//print
	insert_node_at_beginning(100);				//inserting at beginning
	insert_node_at_end(13);					//inserting at end
	del_pos(3);						//deleting node at nth position
        print();						//print
	reverse_linked_list();					//reversing singly linked list
	print();						//print
}
