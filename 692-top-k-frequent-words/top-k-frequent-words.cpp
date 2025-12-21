class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        //step 1 : store frequency
        for(auto &word : words){
            mp[word]++;
        }

        vector<pair<string, int>> v;
        //step 2 : fill with {word, freq}
        for(auto &it : mp){
            v.push_back({it.first, it.second});
        }
        //step 3 : sort the vector with comparator
        auto lamda = [](pair<string, int> p1, pair<string, int> p2){
            if(p1.second == p2.second){
                return p1.first < p2.first;
            }
            return p1.second > p2.second;
        };
        sort(v.begin(), v.end(), lamda);

        //step 4 : top k ko utha lo
        int i = 0;
        vector<string> ans;

        while(i < k){
            ans.push_back(v[i].first);
            i++;
        }
        return ans;
    }
};