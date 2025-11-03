class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        int cur=0;
        int min=INT_MAX;
        for(auto &p : strs)
        {
            if(p.length() < min)
            {
                min=p.length();
            }
        }
        while(1)
        {   
            if(cur >= min)
            {
                return s;
            }    
            char temp=strs[0][cur];
            for(auto &p :strs)
            {
                if(p[cur] != temp)
                {
                    return s;
                }
            }
            cur++;
            s+=temp;
        }
        return s;
    }
};