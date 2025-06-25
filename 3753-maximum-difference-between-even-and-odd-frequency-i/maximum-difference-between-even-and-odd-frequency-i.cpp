class Solution {
public:
    int maxDifference(string s) {
        unordered_map<int, int> freq;

        for(int i = 0; i < s.length(); i++){
            // (97 - 97 = 0), (98 - 97 = 1), (99- 97 = 2)..... so on (122 - 97 = 25)
            // ('a' - 'a' = 0), ('b' - 'a' = 1)........ ASCII values to find the position in the alphabet
            freq[s[i] - 'a']++;
        }

        int minE = INT_MAX, maxO = 0;
        for(auto [v, f] : freq){
            if(f % 2 == 1){
                maxO = max(maxO, f);
            }else{
                minE = min(minE, f);
            }
        }
        return maxO - minE;
    }
};