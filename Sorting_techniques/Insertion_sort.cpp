#include<bits/stdc++.h>
using namespace std;

void Insertion_sort(int arr[],int n){
    int j,key;
    for(int i=1;i<n;i++){
        key=arr[i];
        for(j=i-1;j>=0 and arr[j]>key;j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
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

    Insertion_sort(arr,n);

    cout<<"Sorted array :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

/* Time complexity : O(n²)
   Auxilary space : O(1)  */
