class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 3 pointer approach
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // Loop from k to 0
        while (k > -1){
            // Means we sorted all of nums1, but we still have to place nums2 elements
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