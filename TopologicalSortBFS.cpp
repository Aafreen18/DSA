#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

//Kahn`s Algorithm
class TopologicalSortBFS{
    public:
    unordered_map<int, list<int>> adj;
    vector<int> indegree;
    queue<int>q;
    vector<int>ans;
    
    //create adjacency list
    void adjacencyList(vector<vector<int>> edges, int v, int e){
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
        }

        //create indegree    
        for(auto i: adj){
            for(auto j: i.second){
                indegree[j]++;
            }
        }

        // pushing 0 indegree nodes
        for(int i=0; i<v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }

    vector<int> topologicalSort(queue<int> q, vector<int> ans){
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            //neighbor indegree update
            for(auto neighbor: adj[frontNode]){
                indegree[neighbor]--;

                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }

    
};