// User function Template for C++
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <climits>
using namespace std;

class Solution {
  public:
    void topologicalsortDFS(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int,list<pair<int, int>>> &adj){
        visited[node] = true;
       
        for(auto i: adj[node]){
            if(!visited[i.first]){
                topologicalsortDFS(i.first, visited, s, adj);
            }
        }
        
        //imp
        s.push(node);
    }
  
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,list<pair<int, int>>> adj;
        stack<int> s;
        unordered_map<int, bool> visited;
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
        }
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                topologicalsortDFS(i, visited, s, adj);
            }
        }
        
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        while(!s.empty()){
            int node = s.top();
            s.pop();
            
            if(dist[node] != INT_MAX){
                for(auto neighbor: adj[node]){
                    int connectedNode = neighbor.first;
                    int weight = neighbor.second;
                    
                    if (dist[connectedNode] > dist[node] + weight) {
                        dist[connectedNode] = dist[node] + weight;
                    }
                }
            }
        }
        
        for(int i=0; i<V; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
    
    
};
