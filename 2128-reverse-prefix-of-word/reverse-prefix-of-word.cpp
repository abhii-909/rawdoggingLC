class Solution {
public:
    string reversePrefix(string word, char ch) {
    int idx = word.find(ch);
        if (idx == -1) {
            return word;
        }

        string result;
        for (int i = 0; i < word.length(); i++) {
            if (i <= idx) {
                result += word[idx - i];
            }
            else {
                result += word[i];
            }
        }
        return result;
    }
};