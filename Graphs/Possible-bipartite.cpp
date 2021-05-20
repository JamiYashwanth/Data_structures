class Solution {
public:
    map<int,vector<int>> mp;
    
    bool bfs(int vertex, vector<int>& color){
        color[vertex]=1;
        queue<int> q;
        q.push(vertex);
        while(!q.empty()){
            int k = q.front();
            q.pop();
            for(auto i=mp[k].begin();i!=mp[k].end();i++){
                if(color[*i]!=-1){
                    if(color[*i]==color[k]) return false;
                }
                else{
                    color[*i]=1-color[k];
                    q.push(*i);
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(auto i : dislikes){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        vector<int> color(n+1,-1);
        bool flag = false;
        for(int i=1;i<=n;i++){
            if(color[i]==-1 and flag == false){
                if(bfs(i,color)) flag = true;
            }
        }
        return flag;
    }
};
