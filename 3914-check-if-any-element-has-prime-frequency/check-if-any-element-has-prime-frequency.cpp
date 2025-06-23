class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int num : nums) freq[num]++;

        for(int count : freq){
            if(count > 1 && isPrime(count)) return true;
        }
        return false;
    }
    bool isPrime(int n){
        if(n <= 1) return false;
        if(n == 2) return true;

        for(int i = 2; i*i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
};