class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        int n=path.size();
        if(path[n-1]=='/') path.pop_back();
        stack<string>s;
        istringstream in(path);
        string s1;
        while(getline(in, s1, '/')){
            if(s1==".."){
                if(!s.empty()) s.pop();
            }
            else if(s1!="" && s1!=".") s.push(s1);
        }
        while(!s.empty()){
            ans='/'+s.top()+ans;
            s.pop();
        }
        if(ans=="") return "/";
        return ans;
    }
};