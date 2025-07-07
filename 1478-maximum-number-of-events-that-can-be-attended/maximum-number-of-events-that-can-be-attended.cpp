class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // sort events by start day
        sort(events.begin(), events.end());

        // min-heap for end days
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int i = 0, cnt = 0;
        int n = events.size();

        // find the last day to simulate
        int lastDay = 0;
        for(const auto& e : events) lastDay = max(lastDay, e[1]);

        // simulate each day
        for(int day = 1; day <= lastDay; day++){
            // add all events starting today
            while(i < n && events[i][0] == day){
                minHeap.push(events[i][1]);
                i++;
            }
            // remove expired events
            while(!minHeap.empty() && minHeap.top() < day){
                minHeap.pop();
            }
            // attend one event with earliest end
            if(!minHeap.empty()){
                minHeap.pop();
                cnt++;
            }
            // early stop
            if(i == n && minHeap.empty()) break;
        }
        return cnt;
    }
};