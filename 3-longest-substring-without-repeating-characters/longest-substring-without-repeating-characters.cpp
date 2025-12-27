class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, maxLen = 0;
        unordered_map<char, int> mp;

        for(int r = 0; r < s.length(); r++){
            char c = s[r];
            mp[c] = mp[c] + 1;

            while(mp[c] > 1){
                char leftChar = s[l];
                mp[leftChar] = mp[leftChar] - 1;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};