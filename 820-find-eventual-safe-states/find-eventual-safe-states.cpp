// //Using DFS-cycle detection

// class Solution {
// public:
//     bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& vis, vector<bool>& inRecursion) {
//         vis[u] = true;
//         inRecursion[u] = true;
        
        
//         for(int &v : adj[u]) {
//             //if not vis, then we check for cycle in DFS
//             if(vis[v] == false && isCycleDFS(adj, v, vis, inRecursion)){
//                 return true;
//             } else if(inRecursion[v] == true){
//                 return true;
//             }
//         }
        
//         inRecursion[u] = false;
//         return false;
        
//     }
    
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int V = graph.size();
//         vector<bool> vis(V, false);
//         vector<bool> inRecursion(V, false);
        
//         for(int i = 0; i < V; i++) {
//             if(!vis[i]){
//                 isCycleDFS(graph, i, vis, inRecursion);
//             }
//         }
        
//         vector<int> safeNodes;
//         for(int i = 0; i < V; i++) {
//             if(!inRecursion[i]){
//                 safeNodes.push_back(i);
//             }
//         }
        
//         return safeNodes;
//     }
// };

// ________________________________________________________________________________________________

// USING BFS (Topological sort)

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<vector<int>> adj(V);
        
        
        queue<int> que;
	    vector<int> indegree(V, 0);
	    int count = 0;
	    //1
	    for(int u = 0; u < V; u++) {
	        for(int &v : graph[u]) {
                adj[v].push_back(u);
	            indegree[u]++;
	        }
	    }
	    
	    //2. Fill que, indegree with 0
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	            count++;
	        }
	    }
	    
	    //3. Simple BFS
        vector<bool> safe(V, false);
	    while(!que.empty()) {
	        int u = que.front();
	        que.pop();
            safe[u] = true;
	        
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            
	            if(indegree[v] == 0) {
	                que.push(v);
	                count++;
	            }
	            
	        }
	    }
	    
	    vector<int> safeNodes;
        for(int i = 0; i < V; i++) {
            if(safe[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};