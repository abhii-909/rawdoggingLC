class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> dirs = 
    {
        {-1, 0}, {1, 0}, {0, 1}, {0, -1}
    }; 

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> res(m, vector<int>(n, 1e9));

        priority_queue<p, vector<p>, greater<p>> pq;

        auto isSafe = [&](int x, int y){
            return (x >= 0 && x < m && y >= 0 && y < n);
        };

        res[0][0] = 0;
        pq.push({0, {0,0}});

        while(!pq.empty()){
            int diff = pq.top().first;
            auto coord = pq.top().second;
            pq.pop();

            int x = coord.first;
            int y = coord.second;

            if(x == m-1 && y == n-1) return diff;

            for(auto &dir : dirs){
                int xNew = dir[0] + x;
                int yNew = dir[1] + y;

                if(isSafe(xNew, yNew)){
                    int absDiff = abs(heights[x][y] - heights[xNew][yNew]);
                    int maxDiff = max(diff, absDiff);

                    if(res[xNew][yNew] > maxDiff){
                        res[xNew][yNew] = maxDiff;
                        pq.push({maxDiff, {xNew,yNew}});
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
};