class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, maxLen = 0;
        unordered_set<char> cs;

        for(int r = 0; r < s.length(); r++){
            while(cs.find(s[r]) != cs.end()){
                cs.erase(s[l]);
                l++;
            }

            cs.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};