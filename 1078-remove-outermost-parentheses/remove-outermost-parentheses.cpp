class Solution {
public:
    string removeOuterParentheses(string s) {
        string st = "";
        int cnt = 0;

        for(char ch : s){
            if(ch == '('){
                if(cnt > 0) st += ch;
                cnt++;
            }
            else if( ch == ')' ) {
                cnt--;
                if(cnt > 0) st += ch;
            }
        }
        return st;
    }
};