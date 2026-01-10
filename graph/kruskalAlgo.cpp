// Total time complexity ---O(N * α(n))

#include <vector>           // for std::vector
#include <unordered_map>    // for std::unordered_map
#include <list>             // for std::list
#include <set>              // for std::set
#include <climits>          // for INT_MAX
#include <utility>          // for std::pair, std::make_pair
#include <algorithm>  
#include<queue>
using namespace std;

//Topics - DISJOINT-SET ,UNION FIND]

class Solution {
  public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[2]<b[2];
    }
    
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(), edges.end(), cmp);
        
        vector<int> parent(V);
        for(int i = 0; i < V; i++) parent[i] = i;

        vector<int> rank(V, 0);
        int totalWeight = 0;
        
        for(int i=0; i<edges.size(); i++){
            int u = findParent(parent, edges[i][0]);
            int v = findParent(parent, edges[i][1]);
            int wt = edges[i][2];
            
            //It means they do not contain in the same component----so do union of both
            if(u != v){
                totalWeight += wt;
                unionSet(u, v, parent, rank);
            }
        }
        
        return totalWeight;
    }
    
    //This combination gives an amortized time complexity of findParent -- O(α(n)) per findParent or unionSet call, where α(n) is the inverse Ackermann function —it grows slower than log n, practically constant (≤ 4 for all realistic n).
    //finding the ultimate(root) parent...not the immediate parent that is just above the node in the tree ---It is called path compression
    int findParent(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = findParent(parent, parent[node]);
    }
    
    //union find by rank
    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
        u = findParent(parent, u);
        v = findParent(parent, v);
        
        //the one with higher rank will become parent;
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else{
            parent[v] = u;// if the rank is same anyone can become parents and increase the rank of parent
            rank[u]++;
        }
    }
};