class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        if(s.empty()) return "";

        sort(s.begin(), s.end());

        string first = s[0];
        string last = s[s.size() - 1];

        string ans = "";

        for(int i = 0; i < first.length(); i++){
            if(i < last.length() && first[i] == last[i]){
                ans += first[i];
            }else{
                break;
            }
        }
        return ans;
    }
};