#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, list<int>> adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        
        vector<bool> visited(V, false);

        stack<int> s;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                topologicalsortDFS(i, visited, s, adj);
            }
        }
        
        vector<int> ans;
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
    
    void topologicalsortDFS(int node, vector<bool> &visited, stack<int> &s, unordered_map<int,list<int>> &adj){
        visited[node] = true;
       
        for(auto i: adj[node]){
            if(!visited[i]){
                topologicalsortDFS(i, visited, s, adj);
            }
        }
        
        //imp
        s.push(node);
    }

};