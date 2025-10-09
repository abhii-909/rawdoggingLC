class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        // int n = heights.size(), 
        int maxArea = 0;
        heights.push_back(0);

        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                int area = h * width;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        return maxArea;
    }
};