class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        //base case
        if(intervals.size() == 0) return ans;
        //sort
        sort(intervals.begin(), intervals.end());
        //first elem
        ans.push_back(intervals[0]);
        int j = 0;
        
        for(int i = 1; i < intervals.size(); i++){

            //if overlapping
            if(ans[j][1] >= intervals[i][0]){
                ans[j][1] = max(ans[j][1], intervals[i][1]);
            }
            //not overlapping
            else{
                j++;
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};