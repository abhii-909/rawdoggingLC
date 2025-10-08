class Solution {
public:
    #define ll long long
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> ans;
        ans.reserve(spells.size());

        for(int e : spells){
            // potion * spell >= success => potion >= success/spell;
            ll need = (success + e - 1) / e;

            // find the first potion >= need using binary search
            auto it = lower_bound(potions.begin(), potions.end(), need);
            // counts how many steps from potions.begin() to it
            int idx = it - potions.begin();

            // count how many potions from idx to end are valid
            int cnt = potions.size() - idx;
            ans.push_back(cnt);
        }
        return ans;
    }
};