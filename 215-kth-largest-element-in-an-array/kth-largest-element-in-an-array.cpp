class Solution {
public:

    int partition(vector<int>& nums, int L, int R){
        int  P = nums[L];
        int i = L + 1, j = R;   // (L+1) to handle only 1 element wala case

        while(i <= j){
            if(nums[i] < P && nums[j] > P){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if(nums[i] >= P){
                i++;
            }
            if(nums[j] <= P){
                j--;
            }
        }
        swap(nums[L], nums[j]);
        return j; // P is at jth idx
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int L  = 0, R = n-1;
        int pivot_idx = 0;

        // kth largest pivot element -> nums[k-1] (jab descending order mei partition karenge)
        while(true){
            pivot_idx = partition(nums, L, R);

            if (pivot_idx == k-1) break;
            else if (pivot_idx > k-1) R = pivot_idx - 1;   //chaiye tha 2nd largest milgaya 4th largest
            else L = pivot_idx + 1;
        }
        return nums[pivot_idx];
    }
};