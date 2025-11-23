class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = 0;
        vector<int> ones, twos;

        for (int x : nums) {
            total += x;
            if (x % 3 == 1) ones.push_back(x);
            else if (x % 3 == 2) twos.push_back(x);
        }

        sort(ones.begin(), ones.end());
        sort(twos.begin(), twos.end());

        int mod = total % 3;

        if (mod == 0) return total;

        int ans = 0;

        if (mod == 1) {
            int remove1 = (ones.size() >= 1 ? ones[0] : INT_MAX);
            int remove2 = (twos.size() >= 2 ? twos[0] + twos[1] : INT_MAX);
            int loss = min(remove1, remove2);
            if (loss == INT_MAX) return 0;
            ans = total - loss;
        } 
        else {  // mod == 2
            int remove1 = (twos.size() >= 1 ? twos[0] : INT_MAX);
            int remove2 = (ones.size() >= 2 ? ones[0] + ones[1] : INT_MAX);
            int loss = min(remove1, remove2);
            if (loss == INT_MAX) return 0;
            ans = total - loss;
        }

        return ans;
    }
};
