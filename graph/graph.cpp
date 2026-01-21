#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> m;
    queue<int> q;

    void addEdge(int u, int v, bool direction) {
        // direction = 0 for undirected graph
        // direction = 1 for directed graph

        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u); // Add this for an undirected graph
        }
    }

    void printAdjList(){
        for(auto i:adj ){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

    //bfs traversal
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        unordered_map<int, bool> visited;
        vector<int> ans;
        
        //for disconnected nodes
        // for(int i=0; i<adj.size(); i++){
        //     if(!visited[i]){
        //         BFS(visited, ans, i, adj);
        //     }
        // }
        
        //for connected nodes
        BFS(visited, ans, 0, adj);
        
        return ans;
    }
    
    void BFS(unordered_map<int, bool> &visited, vector<int> &ans, int node, vector<vector<int>> &adj){
        queue<int> q;
        q.push(node);
        visited[node] = true;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            // store frontNode
            ans.push_back(frontNode);
            
            // store the neighbours of all node
            for(auto i : adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
            
        }
    }


    //dfs traversal
    void DFS(int node, unordered_map<int, bool> &visited, vector<vector<int>>& adj, vector<int> &components){
        
        components.push_back(node);
        visited[node] = true;
        
        for( auto i : adj[node]){
            if(!visited[i]){
                DFS(i, visited, adj, components);
            }
        }
    }
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int, bool> visited;
        vector<int> ans;
        
        for(int i=0; i<adj.size(); i++){
            if(!visited[i]){
                DFS(i, visited, adj, ans);
                
                //disjoint nodes
                //vector<int> components;
                //DFS(i, visited, adj, components);
                //ans.push_back(components);
            }
        }
        
        return ans;
    }

    //cycle detection of undirected graph ->BFS
    bool isCycleUndirect(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int, bool> visited;
        
        for(int i=0; i < adj.size(); i++){
            if(!visited[i]){
                //bool ans = cycleDetectionBFS(i, visited, adj);
                
                bool ans = cycleDetectionDFS(i, -1, visited, adj);
                
                if(ans){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool cycleDetectionBFS(int srcNode, unordered_map<int, bool> &visited, vector<vector<int>> &adj){
        unordered_map<int, int> parent;
        
        parent[srcNode] = -1;
        visited[srcNode] = 1;
        
        queue<int> q;
        q.push(srcNode);
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            // store the neighbours of all node
            for(auto i : adj[frontNode]){
                if(visited[i] && i != parent[frontNode]){// if parent of a node and neighbour of the same node are not equal, then there is cycle
                    return true;
                }
                else if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                    parent[i] = frontNode;
                }
                //visited[i] == true && i == parent[frontNode] -> neglect //jo ek node ka neighbour hai wahi uska parent hoga toh cycle nhi hoga -- iska matlab hai wo ussi parent se aaya hai matlab ek hi path se aaya hai 
            }
            
        }
        
        return false;
    }
    
    //undirected graph for dfs
    bool cycleDetectionDFS(int node, int parent, unordered_map<int, bool> &visited, vector<vector<int>>& adj){
        visited[node] = true;
        
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                bool ans = cycleDetectionDFS(neighbour, node, visited, adj);
                
                if(ans){
                    return true;
                }
            }
            else if(neighbour != parent){
                return true;
            }
        }
        
        return false;
    }


    //cycle detection of directed graph DFS
    bool isCyclicDirect(vector<vector<int>> &adj) {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> DFSvisited;
        // code here
        for(int i=0; i<adj.size(); i++){
            if(!visited[i]){
                bool ans = cycleDetectionDFS(i, visited, adj, DFSvisited);
                
                if(ans){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool cycleDetectionDFS(int node, unordered_map<int, bool> &visited, vector<vector<int>> &adj, unordered_map<int, bool> &DFSvisited){
        visited[node] = true;
        DFSvisited[node] = true;
        
        for(auto i : adj[node]){
            if(!visited[i]){
                bool ans = cycleDetectionDFS(i, visited, adj, DFSvisited);
                
                if(ans){
                    return true;
                }
            }
            else if(DFSvisited[i]){// node visited is true and dfsVisited of the node is also true -> cyclic
                return true;
            } 

            // node visited is true and dfsVisited of the node is also false -> skip
            
        }
        
        DFSvisited[node] = false;
        return false;
    }

    //cycle detction of directed graph using BFS
        vector<int> indegree;
        void adjacencyList(vector<vector<int>> edges, int v, int e){
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int w = edges[i][1];   

            adj[u].push_back(w);
        }

        // create indegree    
        for(auto i : adj){
            for(auto j : i.second){
                indegree[j]++;
            }
        }

        // pushing 0 indegree nodes
        for(int i = 0; i < v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }

    bool topologicalSort(queue<int>& q, vector<int>& ans, int n){
        int cnt = 0;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);
            cnt++;

            // neighbor indegree update
            for(auto neighbor : adj[frontNode]){
                indegree[neighbor]--;

                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        if(cnt == n) return true;
        return false;
    }
};

int main(){
    graph g;
    g.addEdge(1, 2, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 4, true); // Directed edge from 3 to 4
    g.addEdge(4, 1, false);

    cout << "Graph Representation:\n";
    g.printAdjList();


    return 0;
}

