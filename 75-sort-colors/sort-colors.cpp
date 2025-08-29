class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int i = 0;     // for 0
        int j = 0;     // for 1
        int k = n-1;   // for 2 (n-1 isliye kyuki 2 sabse bada hai isliye last mei hi hoga humesha)

        while(j <= k){
            if(nums[j] == 1) j++;  // j happy kyuki j ko 1 chaiye aur milgaya

            else if(nums[j] == 2){
                swap(nums[j], nums[k]);   // k aur j mei rola chidh gaya kyuki k ko 2 chaiye
                k--;
            }else{ // nums[j] == 0
                swap(nums[j], nums[i]);   // ab i bolega 0 mere pass hona chaiye
                i++;
                j++;     // j ko ++ kyuki i and j started at the same place
            }
        }
    }
};