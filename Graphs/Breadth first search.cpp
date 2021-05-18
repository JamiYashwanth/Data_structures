#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> graph;
map<int,bool> visited;

void addEdge(int from,int to){
    graph[from].push_back(to);
}

void BFS(int vertex){
    visited[vertex] = true;
    queue<int> queue;
    queue.push(vertex);
    
    while(!queue.empty()){
        int v = queue.front();
        cout<<v<<" ";
        queue.pop();
        for(auto it=graph[v].begin();it!=graph[v].end();it++){
            if(visited[*it]!=true){
                visited[*it]=true;
                queue.push(*it);
            }
        }    
    }
}

int main(){
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    addEdge(3, 4);
    addEdge(4, 1);
    cout<<"BFS : ";
    BFS(3);
}
