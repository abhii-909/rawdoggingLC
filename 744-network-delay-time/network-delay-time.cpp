class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(auto &e : times) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});
        }

        vector<int> res(n + 1, 1e9);
        res[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, src});

        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &it : adj[node]) {
                int next = it.first;
                int wt = it.second;

                if(d + wt < res[next]) {
                    res[next] = d + wt;
                    pq.push({d + wt, next});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i < n+1; i++){
            ans = max(ans, res[i]);
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};