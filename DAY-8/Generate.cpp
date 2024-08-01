class Solution {
    private:
    void rec(string str,vector<string>& ans,int n,int open,int close){
        if(open == n && close==n){
            ans.push_back(str);
            return;
        }
        string str1 = str;
        string str2 = str;
        if(close<open  && open!=n){
            str1+='(';
            rec(str1,ans,n,open+1,close);
            str2 +=')';
            rec(str2,ans,n,open,close+1);
        }
        else if(close>=open){
            str+='(';
            rec(str,ans,n,open+1,close);
        }
        else{
            str+=')';
            rec(str,ans,n,open,close+1);
        }
       
    }
public:
    vector<string> generateParenthesis(int n) {
        string str ="";
        vector<string> ans;
        rec(str,ans,n,0,0);
        return ans;
    }
};