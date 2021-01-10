#include<stdio.h>
#include<stdlib.h>
#define max_size 5
int Top=-1;
void push(int);
void pop();
void top();
void print();

struct node
{
	int data;
	struct node* next;
};

struct node* head;

void push(int n){
    if(Top==max_size-1){
        printf("Stack overflow\n");
    }
    else{
        Top+=1;
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=n;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
        }
        else{
            struct node* temp1=head;
            while(temp1->next!=NULL){
                temp1=temp1->next;
            }
            temp1->next=temp;
        }
    }
}

void top(){
    int k=0;
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("Top element : %d\n",temp->data);
}

void pop(){
    if(Top==-1){
        printf("Stack underflow\n");
        return;
    }
    if(Top!=0){
        struct node* temp=head;
        struct node* k;
        while(temp->next!=NULL){
            k=temp;
            temp=temp->next;
        }
        k->next=NULL;
        free(temp);
    }
    else{
        free(head);
        head=NULL;
    }
    Top-=1;
}

void print(){
	struct node* temp=head;
	printf("Stack : ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main(){
	head=NULL;
    int n;
    bool t=true;
    printf("Enter\n1 for Push\n2 for Pop\n3 for Top\n4 for Stop\n");
    while(t){
        int k;
        scanf("%d",&k);
        switch (k)
        {
            case 1:
                int ele;
                printf("Enter element: ");
                scanf("%d",&ele);
                push(ele);
                print();
                break;
            case 2:
                pop();
                print();
                break;
            case 3:
                top();
                print();
                break;
            case 4:
                t=false;
                print();
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
    }
}
