class Solution {
    public int reverse(int x) {
        int cnt = 0;
        while(x != 0){
            int digit = x % 10; //get the last digit

            if(cnt > Integer.MAX_VALUE/10 || cnt < Integer.MIN_VALUE / 10){  //for the overflow condition
                return 0;
            }

            cnt = cnt * 10 + digit;  //apppend it to cnt
            x /= 10;  //remove the last digit
        }
        return cnt;
    }
}