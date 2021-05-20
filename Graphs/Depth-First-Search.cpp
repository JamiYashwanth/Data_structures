#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> graph;
map<int,bool> visited;

void addEdge(int from,int to){
	graph[from].push_back(to);
}

void DFS(int vertex){
	visited[vertex] = true;
	cout<<vertex<<" ";
	for(auto it=graph[vertex].begin(); it!=graph[vertex].end(); it++){
		if(visited[*it]!=true) DFS(*it);
	}
}

int main(){
    addEdge(0,1);
    addEdge(0, 9);
    addEdge(1, 2);
    addEdge(1,5);
    addEdge(2, 0);
    addEdge(2,6);
    addEdge(2, 3);
    addEdge(3,10);
    addEdge(9, 3);
    cout<<"DFS : ";
    DFS(1);
}
