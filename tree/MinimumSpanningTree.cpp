//Spanning Tree - A spanning tree of a graph is a subgraph that connects all the vertices together without forming any cycles. It includes exactly (V - 1) edges if there are V vertices.There can be multiple MSTs if different sets of edges give the same minimum weight.Removing any edge from an MST will disconnect the graph.

//Minimum Spanning Tree - A Minimum Spanning Tree is a spanning tree where the sum of the edge weights is the smallest possible.

//Common Algorithms to Find MST: 1)Kruskal’s Algorithm 2)Prim’s Algorithm


#include <vector>           // for std::vector
#include <unordered_map>    // for std::unordered_map
#include <list>             // for std::list
#include <set>              // for std::set
#include <climits>          // for INT_MAX
#include <utility>          // for std::pair, std::make_pair
#include <algorithm>  
#include<queue>
using namespace std;

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        // Min-heap: {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> mst(V, false);

        pq.push({0, 0});
        int totalWeight = 0;
        
        while(!pq.empty()){
            auto top = pq.top();
            int wt = top.first;
            int u = top.second;
            
            pq.pop();
            
            if (mst[u]) continue;
            
            //mark minimum node as true
            mst[u] = true;
            totalWeight += wt;
            
            for(auto neighbor: adj[u]){
                int connectedNode = neighbor[0];
                int wt = neighbor[1];
                
                if(mst[connectedNode]==false){
                    pq.push({wt, connectedNode});
                }
            }
        }    
        
        return totalWeight;
    }
};