class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        long long prev = 0, cnt = 0, c = startTime[0];
        vector<long long> pre(n+1,0), suff(n+1, 0);
        for(int i=0; i<n; i++) {
            cnt += startTime[i] - prev;
            prev = endTime[i];
            pre[i] = cnt;
        }
        long long ans = pre[k-1] + (k-1 == n-1 ? eventTime : startTime[k]) - endTime[k-1];
        for(int i=k; i<n; i++) {
            ans = max(ans, pre[i] - pre[i-k] + (i==n-1?eventTime : startTime[i+1]) - endTime[i]);
        }
        return ans;
    }
};