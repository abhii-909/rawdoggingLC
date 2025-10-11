// Gotta learn dp properly

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> damageCount;
        for (int p : power) {
            damageCount[p]++;
        }
        
        vector<pair<int, int>> damages;
        for (auto& [val, cnt] : damageCount) {
            damages.push_back({val, cnt});
        }
        
        int n = damages.size();
        if (n == 1) {
            return (long long)damages[0].first * damages[0].second;
        }
        
        long long three_back = 0;
        long long two_back = (long long)damages[0].first * damages[0].second;
        
        long long one_back;
        if (damages[1].first - damages[0].first < 3) {
            one_back = max(two_back, 
                          (long long)damages[1].first * damages[1].second);
        } else {
            one_back = two_back + 
                      (long long)damages[1].first * damages[1].second;
        }
        
        for (int i = 2; i < n; i++) {
            long long curr_damage = (long long)damages[i].first * 
                                   damages[i].second;
            long long new_dp;
            
            if (damages[i].first - damages[i-1].first > 2) {
                new_dp = curr_damage + one_back;
            } else if (damages[i].first - damages[i-2].first > 2) {
                new_dp = max(one_back, curr_damage + two_back);
            } else {
                new_dp = max(one_back, curr_damage + three_back);
            }
            
            three_back = two_back;
            two_back = one_back;
            one_back = new_dp;
        }
        
        return one_back;
    }
};