// THODI SI BETTER APPROACH HAI W/O STACK TO IMPROVE THE RUNTIME USING A VECTOR INSTEAD


class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string dir;
        stringstream ss(path);

        while(getline(ss, dir, '/')){
            if(dir == "" || dir == ".") continue;     // ignore
            else if(dir == ".."){
                if(!dirs.empty()) dirs.pop_back();    // previous dir
            }else{
                dirs.push_back(dir);                  // valid dir
            }
        }

        // ab simplified string banate hai
        string res;
        for(auto &d : dirs){
            res += "/" + d;
        }
        // if root dir
        if(res.empty()) return "/";
        else return res;
    }
};