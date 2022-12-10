#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Tree{
    public:
        int uid;
        string name;
        bool is_locked;
        int desc_locked = 0;
        vector<Tree*> links;
        Tree* parent;
        Tree(Tree* p,string node_name){
            uid = -1;
            parent = p;
            is_locked = false;
            desc_locked = 0;
            name = node_name;
        }
};

void print(Tree* node){
    queue<Tree*> q;
    q.push(node);
    
    while(!q.empty()){
        Tree* k = q.front();
        cout<<k->name<<" ";
        q.pop();
        for(ll i=0;i<k->links.size();i++){
            q.push(k->links[i]);
        }
    }
}

// Check if any of the Ancestors are locked
bool check_ancestors(Tree* node){
    Tree* k = node->parent;
    while(k!=NULL){
        if(k->is_locked) return false;
        k=k->parent;
    }
    return true;
}

// Check if any of the Descendants are locked
bool check_descendants(Tree* node,ll id,vector<Tree*> &locked_nodes){ 
    Tree* k = node;
    queue<Tree*> q;
    q.push(k);
    while(!q.empty()){
        k = q.front();
        q.pop();
        if(k->is_locked){
            if(k->uid!=id) return false;
            locked_nodes.push_back(k);
        }
        for(auto i : k->links){
            q.push(i);
        }
    }
    return true;
}

/*
    Lock the node
   =>Conditions 
    1. All the Ansectors must be unlocked
    2. All the Descendants must be unlocked 
*/
bool lock(Tree* node ,ll id){
    if(node->is_locked || node->desc_locked>0) return false;
    
    if(!check_ancestors(node)) return false;
    
    Tree* k = node->parent;
    while(k!=NULL){
        k->desc_locked+=1;
        k=k->parent;
    }
    
    // Lock the node
    node->is_locked = true;
    node->uid = id;
    
    return true;
}


/*
    UnLock the node
   =>Conditions 
    1. Node must be locked
    2. Id should match
*/
bool unlock(Tree* node,ll id){
    if(!node->is_locked || node->uid!=id) return false;
    
    Tree* k = node->parent;
    while(k!=NULL){
        k->desc_locked-=1;
        k=k->parent;
    }
    
    // Unlock the node
    node->is_locked = false;
    
    return true;
}


/*
    Upgrade the node
   =>Conditions 
    1. All the Ansectors must be unlocked
    
   =>Process
    1. Unlock all the Locked descendant nodes
    2. Lock the node
*/
bool upgrade(Tree* node,ll id){
    if(!check_ancestors(node)) return false; 
    
    vector<Tree*> locked_nodes;
    if(check_descendants(node,id,locked_nodes)){
        for(auto i : locked_nodes){
            unlock(i,id);
        }
    }
    else return false;
    
    lock(node,id);
    
    return true;
    
}

int main(){
    int n,m,Q;
    cin>>n>>m>>Q;
    
    map<string,Tree*> address_of_node;
    
    int no_of_nodes_added = 0;
    string node_name;
    cin>>node_name;
    Tree* root = new Tree(NULL,node_name);
    address_of_node[node_name] = root;
    no_of_nodes_added+=1;
    
    queue<Tree*> q;
    q.push(root);
    
    while(!q.empty()){
        Tree* node = q.front();
        q.pop();
        
        while(no_of_nodes_added<n and node->links.size()<m){
            cin>>node_name;
            Tree* new_node = new Tree(node,node_name);
            address_of_node[node_name] = new_node;
            node->links.push_back(new_node);
            q.push(new_node);
            no_of_nodes_added+=1;
        }
    }
    
    // Print the Tree
    print(root);
    cout<<endl;
    
    for(ll i=0;i<Q;i++){
        ll op,id;
        string name;
        cin>>op>>name>>id;
        bool flag;
        if(op==1){
            //lock
            flag=lock(address_of_node[name],id);
        }else if(op==2){
            //unlock
            flag=unlock(address_of_node[name],id);
        }else if(op==3){
            //upgrade
            flag=upgrade(address_of_node[name],id);
        }
        
        if(flag) cout<<"True\n";
        else cout<<"False\n";
        
    }
}


/*

Sample input
7
2
7
World
Asia
Africa
India
China
SouthAfrica
Egypt
1 China 9
1 India 9
2 Asia 9
2 India 9
2 India 10
3 World 9
2 Africa 9

Output
World Asia Africa India China SouthAfrica Egypt 
True
True
False
True
False
True
False


Tree looks like 

         World
       /       \
     Asia       Africa
    /    \     /      \ 
  India China South  China
              Afria
              
*/
