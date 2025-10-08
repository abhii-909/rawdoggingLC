class Solution {
public:
    #define ll long long
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> ans;
        ans.reserve(spells.size());

        for(int e : spells){
            ll need = (success + e - 1) / e;

            auto it = lower_bound(potions.begin(), potions.end(), need);
            int idx = it - potions.begin();

            int cnt = potions.size() - idx;
            ans.push_back(cnt);
        }
        return ans;
    }
};