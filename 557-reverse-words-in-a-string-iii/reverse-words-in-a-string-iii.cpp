class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        for(int i = 0; i <= s.size(); i++){
            if(i == s.size() || s[i] == ' '){
                int left = start;
                int right = i-1;
                while(left < right){
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
                start = i+1;
            }
        }
        return s;
    }
};