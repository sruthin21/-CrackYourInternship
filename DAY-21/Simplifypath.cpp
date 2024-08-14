class Solution {
public:
    string simplifyPath(string path) {
        string s = "";
        stack<string> ans;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                continue;
            }
           string temp = "";
           while(path[i]!='/' && i<path.size()){
              temp = temp+path[i];
              i++;
           }
           if(temp==".."){
              if(!ans.empty()){
                ans.pop();
              }
           }
           else if(temp=="."){
            continue;
           }
           else{
            ans.push(temp);
           }
        }
        while(!ans.empty()){
             s= "/"+ans.top()+s;
            ans.pop();
        }
        if(s==""){
            s = "/";
        }
        return s;
    }
};