class Solution {
public:
    int findFinalValue(vector<int>& nums, int a) {
        unordered_set<int> s(nums.begin(), nums.end());

        while(s.find(a) != s.end()){
            a = a*2;
        }
        return a;
    }
};