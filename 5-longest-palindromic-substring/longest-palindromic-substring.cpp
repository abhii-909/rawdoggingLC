class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int maxLen = 0;

        for(int i = 0; i < s.size(); i++){
            // odd
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                int currLen = (r - l + 1);
                if(currLen > maxLen){
                    res = s.substr(l, currLen);
                    maxLen = currLen;
                }
                l--;
                r++;
            }
            //even
            l = i, r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                int currLen = (r - l + 1);
                if(currLen > maxLen){
                    res = s.substr(l, currLen);
                    maxLen = currLen;
                }
                l--;
                r++;
            }
        }
        return res;
    }
};