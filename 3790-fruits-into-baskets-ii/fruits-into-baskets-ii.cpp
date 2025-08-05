class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = fruits.size();

        for(int x : fruits){
            for(int& y : baskets){
                if(x <= y){
                    ans--;
                    y = 0;
                    break;
                }
            }
        }
        return ans;
    }
};