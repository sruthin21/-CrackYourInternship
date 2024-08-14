class Solution {
public:
    string reverseWords(string s) {
        stack<string> ans;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                continue;
            }
            string s1 = "";
            while(s[i]!=' ' && i<s.length()){
                s1+=s[i];
                i++;
            }
            ans.push(s1);
        }
        string res= "";
        while(!ans.empty()){
            res+=ans.top();
            res += " ";
            ans.pop();
        }
        string s1 = "";
        for(int i=0;i<res.length()-1;i++){
            s1+=res[i];
        }
        return s1;
    }
};