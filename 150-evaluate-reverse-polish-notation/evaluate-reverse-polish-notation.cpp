class Solution {
    stack<int> s;
    pair<int, int>extract(){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        return {a, b};
    }
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"){
                pair<int, int> p=extract();
                s.push(p.first+p.second);
            }
            else if(tokens[i]=="-"){
                pair<int, int> p=extract();
                s.push(p.second-p.first);
            }
            else if(tokens[i]=="*"){
                pair<int, int> p=extract();
                s.push(p.first*p.second);
            }
            else if(tokens[i]=="/"){
                pair<int, int> p=extract();
                s.push(p.second/p.first);
            }
            else s.push(stoi(tokens[i]));
        }
        return s.top();
    }
};