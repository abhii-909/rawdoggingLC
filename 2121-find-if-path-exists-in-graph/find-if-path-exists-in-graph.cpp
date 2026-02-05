class Solution {
public:
    bool dfs(unordered_map<int, vector<int>> &adj, int S, int D, vector<bool> &vis){
        if(S == D) return true;

        if(vis[S] == true) return false;

        vis[S] = true;
        
        //explore
        for(auto &node : adj[S]){
            if(dfs(adj, node, D, vis) == true){
                return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // build a adj list
        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        return dfs(adj, source, destination, vis);
    }
};