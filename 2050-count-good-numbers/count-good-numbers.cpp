class Solution {
public:
    const int mod = (int) 1e9 + 7;
    long long power(long x, long n){
        if(n==0) return 1;
        long long temp = power(x, n/2);
        if(n%2==0){
            return (temp * temp)% mod;
        }
        else{
            return (x * temp * temp)% mod;
        }
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        return (int)(power(5, even) * power(4, odd) % mod);
    }
};