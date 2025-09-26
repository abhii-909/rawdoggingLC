class Solution {
public:
    int minimumDeletions(string s) {
        if(s.length() < 2) return 0;

        int aCnt = 0, bCnt = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a') bCnt++;
        }

        int deletion = bCnt;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a') bCnt--;
            else aCnt++;

            deletion = min(deletion, aCnt + bCnt);
        }
        return deletion;
    }
};