class Solution {
public:
    static bool cmp(string a, string b)
    {
        return a.size() < b.size();
    }

    int solve(string a, string b)
    {
        if(b.size() != a.size() + 1) return false;

        int first = 0, second = 0;
        while(first < a.size() && second < b.size()){
            
            if(a[first] == b[second]){
                first++;
                second++;
            }else{
                second++;
            }
        }
        return first == a.size();
    }

    int longestStrChain(vector<string>& words)
    {
        sort(words.begin(), words.end(), cmp);

        int n = words.size();
        vector<int> t(n, 1);
        int ans = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                
                if(solve(words[j], words[i])){
                    t[i] = max(t[i], t[j] + 1);
                }
            }
            ans = max(ans, t[i]);
        }
        return ans;
    }
};