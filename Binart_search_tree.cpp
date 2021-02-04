#include<stdio.h>
#include<stdlib.h>

struct Bstnode{
    int data;
    struct Bstnode* left;
    struct Bstnode* right;
};

struct Bstnode* newnode(int data){
    struct Bstnode* new_node=(struct Bstnode*)malloc(sizeof(struct Bstnode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

struct Bstnode* insert(struct Bstnode* root,int data){
    if(root==NULL){
        root=newnode(data);
    }
    else if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

int search(struct Bstnode* node,int data){
    if(node==NULL){
        return 0;
    }
    if(node->data==data){
        return 1;
    }
    else if(data<node->data){
        search(node->left,data);
    }
    else{
        search(node->right,data);
    }
}

void inorder(struct Bstnode* node){
    if(node==NULL) return;
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);
}

int main(){
    struct Bstnode* root=NULL;
    int k=1;
    while(k){
        int ch,n;
        printf("\n1:Insertion\t 2:Search\t3:exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                n;
                printf("Enter element :");
                scanf("%d",&n);
                if(root==NULL){
                    root=insert(root,n);
                }
                else{
                    insert(root,n);
                }
                break;
            case 2:
                n;
                printf("Enter the element to be searched :");
                scanf("%d",&n);
                if(search(root,n)){
                    printf("Element found!!!\n");
                }
                else{
                    printf("Element not found!!!\n");
                }
                break;
            case 3:
                k=0;
                break;
        }
    }
    printf("\nInorder traversal of BST: ");
    inorder(root);
}
