#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int pivot_index=l,i;
    for(i=l;i<r;i++){
        if(arr[i]<=pivot){
            swap(arr[pivot_index],arr[i]);
            pivot_index+=1;
        }
    }
    swap(arr[pivot_index],arr[r]);
    return pivot_index;
}

void quick_sort(int arr[],int l,int r){
    if(l<r){
        int pivot_index=partition(arr,l,r);
        quick_sort(arr,l,pivot_index-1);
        quick_sort(arr,pivot_index+1,r);
    }
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

    quick_sort(arr,0,n-1);

    cout<<"Sorted array :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

/* Time complexity : O(n*long(n))
   Auxilary space : O(1)  */
