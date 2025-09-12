class Solution {
public:
    // Approach 1=>
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s != t) return false;
        else return true;
    }
};

// TC : O(nlogn)