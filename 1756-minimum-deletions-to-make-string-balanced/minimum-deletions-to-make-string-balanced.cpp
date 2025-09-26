class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0, cnt = 0;

        for(char c: s){
            if(c == 'b') cnt++;
            else if(cnt != 0){
                ans++;
                cnt--;
            }
        }
        return ans;
    }
};