class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,int> mpp;
        int idx=0;

        for(string st:strs){
            string curr= st;
            sort(curr.begin(),curr.end());

            auto it= mpp.find(curr);

            if(it!=mpp.end()){
                ans[it->second].push_back(st);
            }else{
                ans.push_back({st});
                mpp[curr]= idx;
                idx++;
            }
        }
        return ans;
    }
};