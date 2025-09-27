class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);

        //to change adj matrix to list
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 and i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(V, 0);
        int cnt = 0;

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};