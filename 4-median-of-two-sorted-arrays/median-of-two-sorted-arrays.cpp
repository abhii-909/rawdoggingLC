class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int sum = n+m;
        int mIdx = sum/2;
        int i=0, j=0, cnt=0, curr=0, prev=0;

        while (cnt <= mIdx) {
            prev = curr;

            if (i<n && (j>=m || nums1[i] < nums2[j])) { 
                curr = nums1[i++];
            } else {
                curr = nums2[j++];
            }
            cnt++;
        }

        if(sum%2 == 1){
            return curr;
        }else{
            return (prev+curr) / 2.0;
        }
    }
};