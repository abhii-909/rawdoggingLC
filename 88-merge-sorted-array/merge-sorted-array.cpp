class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 3 pointer approach
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (k > -1){
            if(i < 0){
                nums1[k] = nums2[j];
                j--;
            }
            else if (j < 0){
                break;
            }
            else if (nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};