class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, maxLen = 0;
        unordered_map<int,int> basket;
        
        for(int right =0; right < fruits.size(); right++){
            basket[fruits[right]]++;                       // curr fruit ko basket mei daal do

            // 2 se zyada types aane par shrink kardenge window ko
            while(basket.size() > 2){
                basket[fruits[left]]--;
                if(basket[fruits[left]] == 0){
                    basket.erase(fruits[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};