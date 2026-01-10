#include <vector>           // for std::vector
#include <unordered_map>    // for std::unordered_map
#include <list>             // for std::list
#include <set>              // for std::set
#include <climits>          // for INT_MAX
#include <utility>          // for std::pair, std::make_pair
#include <algorithm>        // for std::max
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, list<pair<int,int>>> adj;
        
         for(int i=0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v, wt});
            
        }

        unordered_map<int, int> dist;
        for (int i = 1; i <= n; i++) {
            dist[i] = INT_MAX;
        }
        dist[k] = 0;
       
        //instead of set we can use priority queue(min-heap)
       set<pair<int, int>> s;//distNode, node
       s.insert(make_pair(0, k));

       while(!s.empty()){
            auto top = *s.begin();//pair<int, int>// node having min distance will come out of set

            int nodeDistance = top.first;///0
            int node = top.second;//2
            s.erase(s.begin());

            if(dist[node] != INT_MAX){
                for(auto neighbor: adj[node]){//1
                    int connectedNode = neighbor.first;//1
                    int weight = neighbor.second;//1
                    
                    if (dist[connectedNode] > nodeDistance + weight) {//intmax > 0 + 1
                        auto record = s.find(make_pair(dist[connectedNode], connectedNode));
                        
                        if(record != s.end()){
                            s.erase(record);
                        }

                        dist[connectedNode] = nodeDistance + weight;// 1 -> 1
                        s.insert(make_pair(dist[connectedNode], connectedNode));//1,1
                    }
                }
            }
       }

       int maxTime = -1;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
