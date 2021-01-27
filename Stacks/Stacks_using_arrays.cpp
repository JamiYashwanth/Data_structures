#include<iostream>
#define max_size 100
using namespace std;
int arr[max_size];
int Top=-1;

void push(int n){
    if(Top==max_size-1){
        cout<<"Stack overflow"<<endl;
    }
    else{
        Top+=1;
        arr[Top]=n;
    }
}

void pop(){
    if(Top==-1){
        cout<<"Stack underflow"<<endl;
    }
    else{
        Top--;
    }
}

void top(){
    cout<<"Top element : "<<arr[Top]<<endl;
}

void print(){
    cout<<"Stack :";
    for(int i=0;i<=Top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    bool t=true;
    while(t){
        cout<<"Enter 1:Push 2:Pop 3:Top 4:Stop"<<endl;
        int k;
        cin>>k;
        switch (k)
        {
            case 1:
                int ele;
                cout<<"Enter element: ";
                cin>>ele;
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                top();
                break;
            case 4:
                t=false;
                break;
            default:
                cout<<"Wrong choice"<<endl;
                break;
        }
    }
    print();
}
