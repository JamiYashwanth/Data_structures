#include<bits/stdc++.h>
using namespace std;

void Selection_sort(int arr[],int n){
    int min_index;
    for(int i=0;i<n-1;i++){
        // Finding the minimum element present from indexes i+1 to n 
        min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        // Swapping 
        swap(arr[i],arr[min_index]);
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

    Selection_sort(arr,n);

    cout<<"Sorted array :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

/* Time complexity : O(n²)
   Auxilary space : O(1)  */
