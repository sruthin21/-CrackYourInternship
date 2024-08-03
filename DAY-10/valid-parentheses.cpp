class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        if(s.length()%2==1){
            return false;
        }
        if(s[0]==')' || s[0]==']' || s[0]=='}'){
            return false;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                char temp = s[i];
                ans.push(temp);
            }
            else if(!ans.empty()){
                if(((s[i]==')' && ans.top()=='(')|| (s[i]==']' && ans.top()=='[')||(s[i]=='}' && ans.top()=='{'))){
                     ans.pop();
                }
                else{
                    char temp = s[i];
                    ans.push(temp);
                }   
            }
            else{
                return false;
            }
        }
        if(ans.empty()){
            return true;
        }
        return false;
    }
};