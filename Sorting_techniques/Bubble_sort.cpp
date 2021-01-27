#include<bits/stdc++.h>
using namespace std;

void Bubble_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            // Iterate till n-i-1 coz for every i'th iteration the max element will be positioned at last indexes...
            if(arr[j]>arr[j+1]){
                // swapping adjacent elements...
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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

    Bubble_sort(arr,n);

    cout<<"Sorted array :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

/* Time complexity : O(n²)
   Auxilary space : O(1)  */
