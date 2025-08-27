class Solution {
public:
    string reverseWords(string s) {
        // 1. reverse whole string
        reverse(s.begin(), s.end());

        int i = 0;
        // l and r humare hero jo reverse karenge words ko
        int l =0, r = 0;
        int n = s.length();

        while(i < n){
            while(i < n && s[i] != ' '){ //i ko agar char dikha toh r ko dega aur fir i++ & r++
                s[r] = s[i];
                i++;
                r++;
            }

            if(l < r){ // l      r
                reverse(s.begin()+l, s.begin()+r);  // l se r tak reverse kardiya
                s[r] = ' '; // fir r ko ek space denge after every word
                r++;
                l = r; // l ko r ke pass le aayenge
            }
            i++; // ye toh badhta rahega
        }
        s = s.substr(0, r-1);
        return s;
    }
};