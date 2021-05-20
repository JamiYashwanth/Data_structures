#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> mp;

bool graphColoring(int vertex,vector<int> &visited,int parent){
    visited[vertex]=1;
    for(auto i=mp[vertex].begin();i!=mp[vertex].end();i++){
        if(visited[*i]==0){
            if(graphColoring(*i,visited,vertex)) return true;
        }
        else if(*i != parent) return true;
    }
    return false;
}

int main(){
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    vector<int> visited(v,0);
    bool flag = false;
    for(int i=0;i<v;i++){
        if(visited[i]==0 and flag == false){
            if(graphColoring(i,visited,-1)){
                flag = true;
            }
        }
    }
    if(flag) cout<<"Graph contains cycle\n";
    else cout<<"Graph does'nt contain cycle\n";
}
