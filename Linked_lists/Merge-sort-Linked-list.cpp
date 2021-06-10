#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

struct node{
	int data;
	struct node* next;
};

void middle(struct node*,struct node*,struct node*);
struct node* merge(struct node* first,struct node* second);

struct node* newnode(int d){
	struct node* k=(struct node*)malloc(sizeof(struct node));
	k->data=d;
	k->next=NULL;
	return k;
}

void mergesort(struct node** head){
	struct node* current = *head;
	struct node* first;
	struct node* second;
	if(!current or current->next==NULL) return;
	middle(current,&first,&second);
	mergesort(&first);
	mergesort(&second);
	*head=merge(first,second);
}

void middle(struct node* current,struct node** first,struct node** second){
	struct node* fast;
	struct node* slow;
	slow=current;
	fast=current->next;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			slow=slow->next;
			fast=fast->next;
		}
	}
	*first=current;
	*second=slow->next;
	slow->next=NULL;
}

struct node* merge(struct node* first,struct node* second){
	struct node* ans=NULL;
	if(!first) return second;
	else if(!second) return first;
	if(first->data<=second->data){
		ans=first;
		ans->next=merge(first->next,second);
	}
	else{
		ans=second;
		ans->next=merge(first,second->next);
	}
	return ans;
}

void print(struct node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n;
		struct node* head=NULL;
		for(ll i=0;i<n;i++){
			cin>>k;
			if(head==NULL){
				head=newnode(k);
			}
			else{
				struct node* t=head;
				while(t->next!=NULL){
					t=t->next;
				}
				t->next=newnode(k);
			}
		}
		mergesort(&head);
		print(head);
	}
}
