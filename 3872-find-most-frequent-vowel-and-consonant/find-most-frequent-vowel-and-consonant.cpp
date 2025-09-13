class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> count(26, 0);

        for(char &ch : s){
            count[ch - 'a']++;
        }

        int maxV = 0, maxC = 0;

        for(int i = 0; i < 26; i++){
            char ch = 'a' + i;
            if(count[i] ==0) continue;  //unused

            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                maxV = max(maxV, count[i]);
            }else{
                maxC = max(maxC, count[i]);
            }
        }
        return maxV + maxC;
    }
};