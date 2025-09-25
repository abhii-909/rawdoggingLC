class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string dir;
        stringstream ss(path);

        while(getline(ss, dir, '/')){
            if(dir == "" || dir == ".") continue;      //ignore karke badhte raho

            else if(dir == ".."){
                if(!st.empty()) st.pop();      // pehle wali dir pe aajao
            }else{
                st.push(dir);              // valid dir
            }
        }
        // ab simplified path banate hai
        string res;
        stack<string> temp;       // using stack to reverse the order

        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        while(!temp.empty()){
            res += "/" + temp.top();
            temp.pop();
        }

        // agar root dir hai toh
        if(res.empty()){
            return "/";
        }else{
            return res;
        }
    }
};