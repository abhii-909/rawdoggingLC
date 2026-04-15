class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size(), water = 0;
        int l = 0, r = n-1;
        int lmax = 0, rmax = 0;

        while(l < r){
            lmax = max(lmax, ht[l]);
            rmax = max(rmax, ht[r]);

            if(lmax < rmax){
                water += lmax - ht[l];
                l++;
            }else{
                water += rmax - ht[r];
                r--;
            }
        }
        return water;
    }
};