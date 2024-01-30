class Solution {
    int toNum(string s){
        if(s[0]=='-'){
            int t=0;
            for(int i=1;i<s.size();i++) t=t*10+(s[i]-'0');
            return t*-1;
        }
        int t=0;
        for(int i=0;i<s.size();i++) t=t*10+(s[i]-'0');
        return t;
    }
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> s;
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(a+b);
            }
            else if(tokens[i]=="-"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(b-a);
            }
            else if(tokens[i]=="*"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(a*b);
            }
            else if(tokens[i]=="/"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(b/a);
            }
            else s.push(toNum(tokens[i]));
        }
        return s.top();
    }
};