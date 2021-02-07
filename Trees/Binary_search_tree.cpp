#include<bits/stdc++.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
using namespace std;

struct Bstnode{
    int data;
    struct Bstnode* left;
    struct Bstnode* right;
};

//Creating a new node
struct Bstnode* newnode(int data){
    struct Bstnode* new_node=(struct Bstnode*)malloc(sizeof(struct Bstnode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

//Inserting node to BST
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

//Searching for an element in BST
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
    return 0;
}

//Finding minimum element in BST
int Findmin(struct Bstnode* root){
    if(root==NULL){
        return -1;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}

//Finding maximum element in BST
int Findmax(struct Bstnode* root){
    if(root==NULL){
        return -1;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
}

//Finding height of BST
int height(struct Bstnode* root){
    if(root==NULL){
        return -1;
    }
    return max(height(root->left),height(root->right))+1;
}

//Inorder traversal of BST (Prints in sorted order)
void inorder(struct Bstnode* node){
    if(node==NULL) return;
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);
}

//Preorder traversal of BST 
void preorder(struct Bstnode* root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

//Postorder traversal of BST
void postorder(struct Bstnode* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

//Level-order traversal of BST (Breadth-first strategy)
void levelorder(struct Bstnode* root){
    if(root==NULL) return;
    queue<Bstnode*> q;
    q.push(root);
    while(!q.empty()){
        Bstnode* current=q.front();
        printf("%d ",current->data);
        if(current->left!=NULL) q.push(current->left);
        if(current->right!=NULL) q.push(current->right);
        q.pop();
    }
}

int main(){
    struct Bstnode* root=NULL;
    int k=1;
    while(k){
        int ch,n,min_element,max_element;
        printf("1:Insertion\n2:Search\n3:Find minimum element in BST\n4:Find maximum element in BST\n5:Height of BST\n6:exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
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
                min_element=Findmin(root);
                printf("Min Element is %d\n",min_element);
                break;
            case 4:
                max_element=Findmax(root);
                printf("Max Element is %d\n",max_element);
                break;
            case 5:
                printf("Height of BST is %d\n",height(root));
                break;
            case 6:
                k=0;
                break;
        }
        printf("------------------------------------------------\n");
    }
    printf("\npreorder traversal of BST     :");
    preorder(root);
    printf("\nInorder traversal of BST      :");
    inorder(root);
    printf("\npostorder traversal of BST    :");
    postorder(root);
    printf("\nLevel order traversal of BST  :");
    levelorder(root);
}
