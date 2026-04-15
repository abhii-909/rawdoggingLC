class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;

        for(int i = 0; i < s.length(); i++){

            //odd (i, i)
            int l = i, r = i;

            while(l >= 0 && r < s.length() && s[l] == s[r]){
                int currLen = (r - l + 1);
                if(currLen > maxLen){
                    start = l;
                    maxLen = currLen;
                }
                l--;
                r++;
            }

            //even (i, i+1)
            l = i, r = i+1;

            while(l >= 0 && r < s.length() && s[l] == s[r]){
                int currLen = (r - l + 1);
                if(currLen > maxLen){
                    start = l;
                    maxLen = currLen;
                }
                l--;
                r++;
            }
        }
        return s.substr(start, maxLen);
    }
};