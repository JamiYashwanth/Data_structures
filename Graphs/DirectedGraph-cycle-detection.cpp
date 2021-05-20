#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> mp;

// 0 -> White -> Vertex is not processed yet
// 1 -> Gray  -> Vertex is being processed 
// 2 -> Black -> Vertex and all its descendants are processed

bool graphColoring(int vertex, vector<int>& color){               // DFS
    color[vertex]=1;
    for(auto i=mp[vertex].begin();i!=mp[vertex].end();i++){
        if(color[*i]==1) return true;
        if(color[*i]==0){
            if(graphColoring(*i,color)) return true;
        }
    }
    color[vertex]=2;
    return false;
}

int main(){
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
    }
    vector<int> color(v,0);
    bool flag = false;
    for(int i=0;i<v;i++){
        if(color[i]==0 and flag == false){
            if(graphColoring(i,color)){
                flag = true;
            }
        }
    }
    if(flag) cout<<"Graph contains cycle\n";
    else cout<<"Graph does'nt contain cycle\n";
}
