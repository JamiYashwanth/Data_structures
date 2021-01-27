#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int m,int r){
    int L_size=m-l+1;
    int R_size=r-m;
    int left_arr[L_size];
    int right_arr[R_size];
    for(int i=0;i<L_size;i++){
        left_arr[i]=arr[l+i];
    }
    for(int i=0;i<R_size;i++){
        right_arr[i]=arr[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<L_size && j<R_size){
        if(left_arr[i]<=right_arr[j]){
            arr[k]=left_arr[i];
            k+=1;
            i+=1;
        }
        else{
            arr[k]=right_arr[j];
            k+=1;
            j+=1;
        }
    }
    while(i<L_size){
        arr[k]=left_arr[i];
        k+=1;
        i+=1;
    }
    while(j<R_size){
        arr[k]=right_arr[j];
        k+=1;
        j+=1;
    }
}

void mergesort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int mid=(l+r-1)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}


int main(){
    int n;
    cout<<"Enter number of elements :";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergesort(arr,0,n-1);

    cout<<"Sorted array :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

/* Time complexity : O(n*log(n))
   Auxilary space : O(n)  */
