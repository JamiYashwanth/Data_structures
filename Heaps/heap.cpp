#include<bits/stdc++.h>
using namespace std;

vector<int> heap;

void heapify(int i,int size){
    if(size==-1) size = heap.size();
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    // Max-heap condition
    if(left<size && heap[left]>heap[largest]) largest = left;
    if(right<size && heap[right]>heap[largest]) largest = right;

    /*
     Min-heap condition :-
     if(left<size && heap[left]<heap[largest]) largest = left;
     if(right<size && heap[right]<heap[largest]) largest = right;
    */
    
    if(largest != i){
        swap(heap[largest],heap[i]);
        heapify(largest,size);
    }
}

void insert(int k){
    heap.push_back(k);
    int size=heap.size();
    for(int i=size/2-1;i>=0;i--){
        heapify(i,-1);
    }
}

void heap_sort(){
    for(int i=heap.size()-1;i>0;i--){
        swap(heap[i],heap[0]);
        heapify(0,i);
    }
}

void print(){
    for(auto i: heap) cout<<i<<" ";
    cout<<endl;
}

int main(){
    cout<<"1  - Insert element to heap\n";
    cout<<"2  - Print\n";
    cout<<"3  - Heapsort\n";
    cout<<"-1 - Exit\n\n";
    while(1){
        int ch;
        cin>>ch;
        switch(ch){
            case 1: 
                int k;
                cin>>k;
                insert(k);
                break;
            case 2: 
                print();
                break;
            case 3: 
                heap_sort();
                break;
            default : 
                exit(0);
        }
    }
}
