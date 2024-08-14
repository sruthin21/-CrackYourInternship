
//User function Template for C++
// First Approach
class Solution{
  public:
    bool check(string a,string b){
        unordered_map<char,int> map;
        for(int i=0;i<a.length();i++){
            map[b[i]]--;
            map[a[i]]++;
        }
        for(auto it:map){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>> ans;
        vector<int> vis(string_list.size(),0);
        for(int i=0;i<string_list.size();i++){
            vector<string> l1;
            if(vis[i]==0){
                l1.push_back(string_list[i]);
            }
            else{
                continue;
            }
            for(int j=i+1;j<string_list.size();j++){
                if(vis[j]==0 && string_list[i].length()==string_list[j].length()){
                    if(check(string_list[i],string_list[j])){
                        vis[j]=1;
                        vis[i]=1;
                        l1.push_back(string_list[j]);
                    }
                }
            }
            ans.push_back(l1);
        }
        return ans;
    }
};
// Second Approach
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
       vector<vector<string>> ans;
       unordered_map<string,vector<string>> map;
       for(int i=0;i<string_list.size();i++){
           string s = string_list[i];
           sort(s.begin(),s.end());
           map[s].push_back(string_list[i]);
       }
       for(auto it:map){
           ans.push_back(it.second);
       }
       return ans;
    }
};