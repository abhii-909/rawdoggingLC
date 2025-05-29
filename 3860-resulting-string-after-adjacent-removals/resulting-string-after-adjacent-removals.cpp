class Solution {
public:
    string resultingString(string s) {
        string stack;

        for (char c : s) {
            if (!stack.empty()) {
                char top = stack.back();
                if ((abs(top - c) == 1) || (top == 'a' && c == 'z') || (top == 'z' && c == 'a')) {
                    stack.pop_back(); 
                    continue;
                }
            }
            stack.push_back(c); 
        }

        return stack;
    }
};