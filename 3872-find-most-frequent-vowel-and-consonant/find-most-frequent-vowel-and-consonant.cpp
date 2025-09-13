class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map <char, int> freq;

        for(char &ch : s){
            freq[ch]++;
        }

        int maxV = 0, maxC = 0;
        for(auto &p : freq){
            char ch = p.first;
            int f = p.second;

            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                maxV = max(maxV, f);
            }else{
                maxC = max(maxC, f);
            }
        }
        return maxV + maxC;
    }
};