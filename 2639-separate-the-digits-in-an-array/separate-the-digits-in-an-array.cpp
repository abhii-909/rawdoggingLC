class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(int x : nums){
            vector<int> temp;

            while(x > 0){
                int d = x % 10;
                x = x/10;
                temp.push_back(d);
            }
            reverse(temp.begin(), temp.end());
            for(int x : temp) ans.push_back(x);
        }
        return ans;
    }
};