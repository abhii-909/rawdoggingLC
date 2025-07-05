class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int , int> freq;
        int result = -1;

        for(auto num : arr){
            freq[num]++;
        }

        for(const auto& [num, count] : freq){
            if(num == count){
                result = max(result, num);
            }
        }
        return result;
    }
};