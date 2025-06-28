class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Pair elements with indices
        vector<pair<int , int>> pairs;
        for(int i = 0; i < n; i++){
            pairs.push_back({nums[i], i});
        }

        // Step 2: Sort by value descending
        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b){
            return a.first > b.first;
        });

        // Step 3: Keep top k elements
        pairs.resize(k);

        // Step 4: Sort by original index to maintain order
        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b){
            return a.second < b.second;
        });

        // Step 5: Extract values
        vector<int> result;
        for(auto& p : pairs){
            result.push_back(p.first);
        }
        return result;
    }
};