// Dijkstra can not be used in negative edges 
//-> we move from one node to another value gets added and if we go back to previous location, its value again added in positive edge so we dont prefer to go back, rather revisiting the previous node 
// but in negative case if we use dijkstra, when it will go to previous node its value gets decreased and will revisit the previous node that makes our answer wrong



//Bellman Ford use case -> 1)detect negative cycle 2)Find shortest path 3)Directed graph with neg wt

// User function Template for C++
#include <vector>           // for std::vector
#include <unordered_map>    // for std::unordered_map
#include <list>             // for std::list
#include <set>              // for std::set
#include <climits>          // for INT_MAX
#include <utility>          // for std::pair, std::make_pair
#include <algorithm>  
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        //min distance from the source to all other vertices
        for(int i=0; i<V-1; i++){
            
            for(int j=0; j<edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                
                if(dist[u] != INT_MAX && dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        //check for neq wt cycle
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            if(dist[u] != INT_MAX && dist[v] > dist[u] + w){
                return {-1};
            }
        }
        
        for (int i=0; i < V; i++) {
            if (dist[i] == INT_MAX){
                dist[i] = 1e8;
            }
        }
        
        return dist;
        
    }
};
