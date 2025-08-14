class Solution {
public:
    string largestGoodInteger(string num) {
        string str = "";
        for (int i = 0; i + 2 < num.size(); i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string s = num.substr(i, 3);
                str = max(str, s);
            }
        }
        return str;
    }
};