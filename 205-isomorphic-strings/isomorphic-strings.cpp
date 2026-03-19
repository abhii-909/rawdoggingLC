class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for(int i = 0; i < s.size(); i++){
            char x = s[i], y = t[i];

            if(mp1.count(x) && mp1[x] != y) return false;
            if(mp2.count(y) && mp2[y] != x) return false;

            mp1[x] = y;
            mp2[y] = x;
        }
        return true;
    }
};