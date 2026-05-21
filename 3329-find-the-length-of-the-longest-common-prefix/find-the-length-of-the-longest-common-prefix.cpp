class Solution {
public:
    int digits(int num) {
        return to_string(num).size();
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        
        // Store all prefixes of arr1
        for(int x : arr1) {
            
            while(x > 0) {
                st.insert(x);
                x /= 10;
            }
        }
        
        int ans = 0;
        
        // Check prefixes of arr2
        for(int x : arr2) {

            while(x > 0) {
                
                if(st.count(x)) {
                    ans = max(ans, digits(x));
                }
                x /= 10;
            }
        }
        
        return ans;
    }
};