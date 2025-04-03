class Solution {
public:
    int mySqrt(int x) {
        int start = 1;
        int end = x;

        while(start <= end){
            long long mid = start + (end - start) /2;
            long long ans = (mid * mid);

            if(ans <= x){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return end;
    }
};