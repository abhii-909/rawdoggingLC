class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st;

        int num = 0;
        int result = 0;
        int sign = 1;

        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');     //number banate chalo
            }else if(s[i] == '+'){
                //number bangaya hoga already
                //result mei add kardo
                result += (num * sign);
                num = 0;
                sign = 1;
            }else if(s[i] == '-'){
                //number bangaya hoga already
                //result mei add kardo
                result += (num * sign);
                num = 0;
                sign = -1;
            }else if(s[i] == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }else if(s[i] == ')'){
                result += (num * sign);       //bracket ke andar ka result hai ye
                num = 0;

                int stack_sign = st.top(); st.pop();
                int last_result = st.top();st.pop();

                result *= stack_sign;
                result += last_result;
            }
        }
        result += (num * sign);
        return result;
    }
};