class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int b1 = -1, b2 = -1;
        int cnt1 = 0, cnt2 = 0;
        int ans = 0, left = 0;

        // sliding window approach
        for(int right = 0; right < n; right++){
            // fruit 1
            if(b1 == fruits[right]){
                cnt1++;
            }
            // fruit 2
            else if(b2 == fruits[right]){
                cnt2++;
            }
            // baskets are empty
            else if(b1 == -1){
                b1 = fruits[right];
                cnt1++;
            }else if(b2 == -1){
                b2 = fruits[right];
                cnt2++;
            }
            // third type
            else{
                while(cnt1 > 0 && cnt2 > 0){
                    if(b1 == fruits[left]){
                        cnt1--;
                    }else if(b2 == fruits[left]){
                        cnt2--;
                    }
                    left++;
                }
                // whatever fruit is discarded we replace it's basket with the new type:arr[right]
                if(cnt1 == 0){
                    b1 = fruits[right];
                    cnt1++;
                }else if(cnt2 == 0){
                    b2 = fruits[right];
                    cnt2++;
                }
            }
            // the current window size will be the answer
            ans = max(ans, right - left + 1);
        }
        return ans; // max size found
    }
};