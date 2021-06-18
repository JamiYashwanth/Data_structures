#include<bits/stdc++.h>
using namespace std;

class Trie {
public:
    /*=========Trie structure============*/
    struct TrieNode{                              
        char val;
        struct TrieNode* child[26];
        int wordEnd;
    };
    
    /*=========Root of the Trie==========*/
    TrieNode* root;                                
    
    /*==============Creating newNode================*/ 
    TrieNode* newNode(char ch, int count){
        TrieNode* node = new TrieNode;
        node->val=ch;
        if(count == 1) node->wordEnd+=1; 
        else node->wordEnd=count;
        for(int i=0;i<26;i++){
            node->child[i]=NULL;                   // Initializing all childs to NULL
        }
        return node;
    }
    
    /*========Initialize your data structure here==========*/
    Trie() {
        root =newNode(' ',0);   // Assigning root to Empty character 
    }
    
    /*========Inserts a word into the trie================*/
    void insert(string word) {
        TrieNode* root1 = root; 
        for(int i=0;i<word.length();i++){
            int index=word[i]-'a';
            if(root1->child[index]==NULL){
                if(i==word.length()-1) root1->child[index]=newNode(word[i],1);         
                else root1->child[index]=newNode(word[i],0);
                root1=root1->child[index];
            }
            else{
                root1=root1->child[index];
                if(i==word.length()-1) root1->wordEnd+=1;
            }
        }
    }
    
    /*========Deletes a word into the trie================*/
    void Delete(string word) {
        TrieNode* root1 = root; 
        for(int i=0;i<word.length();i++){
            int index=word[i]-'a';
            root1=root->child[index];
        }
        root1->wordEnd=0;    // wordEnd equals to ZERO indicates that word does'nt exists in Trie
    }
    
    /*=======Returns if the word is in the trie============*/
    bool search(string word) {
        TrieNode* temp=root;
        for(int i=0;i<word.length();i++){
            int index = word[i]-'a';
            if(temp->child[index]==NULL){
                return 0;
            }
            temp=temp->child[index];
            if(i==word.length()-1 and temp->wordEnd==0){
                return 0;
            }
        }
        return 1;
    }
    
    /*=======Returns if there is any word in the trie that starts with the given prefix====*/
    bool startsWith(string prefix) {
        TrieNode* temp=root;
        for(int i=0;i<prefix.length();i++){
            int index = prefix[i]-'a';
            if(temp->child[index]==NULL) return 0;
            temp=temp->child[index];
        }
        return 1; 
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/**
 * Time-complexity :-
    -> Insertion - O(M)
    -> Deletion - O(M)
    -> Searching - O(M)
 * Where, M = Word length
*/

/*

Input:-
    ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
    [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output:-
    [null, null, true, false, true, null, true]

*/