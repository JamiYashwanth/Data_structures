#include<bits/stdc++.h>
using namespace std;

int minDist(vector<int> value, vector<bool> visited){
    int _min = INT_MAX;
    int index;
    for(int i = 0 ; i < visited.size(); i++){
        if(visited[i]==false and value[i]<=_min){
            _min = value[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(vector<vector<int>> graph, vector<int>& value, vector<bool>& visited, vector<int>& parent,  int source){
    int n = graph.size();
    value[source] = 0;
    
    for(int i = 0; i < n-1; i++){
        int u = minDist(value,visited);                          // Selection of minimum value index
        visited[u]=true;                                         // Assigning index as visited
        for(int j = 0; j < n; j++){
            if(visited[j]==false and graph[u][j]!=0){
                if(value[u]+graph[u][j]<value[j]){
                    parent[j]=u;
                    value[j]=value[u]+graph[u][j];
                }
            }
        }
    }
}


int main(){

    // Graph creation using 2D-vector
    vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    int n = graph.size();
    vector<int> value(n);
    vector<bool> visited(n);
    vector<int> parent(n);

    for(int i = 0; i < n; i++){
        value[i] = INT_MAX;         // Initializing all values to INT_MAX
        visited[i] = false;         // Initializing all values to false ( i.e, Unvisited )
    }

    parent[0]=-1;

    dijkstra(graph, value, visited, parent, 0);
    
    // Printing least distance 
    for(int i = 0; i < n; i++){
        cout<<i<<" "<<value[i]<<endl;
    }

    // Graph 
    for (int i = 1; i < n; i++) cout<<parent[i]<<" - "<<i<<"\n";
}
