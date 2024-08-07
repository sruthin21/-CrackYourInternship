class Solution {
    private:
    void solve(set<vector<int>> &ans,vector<int> ar,vector<int> &arr,int j){
        if(ar.size()==arr.size()){
            ans.insert(ar);
            return;
        }
        for(int i=j;i<arr.size();i++){
             ar.push_back(arr[i]);
             swap(arr[i],arr[j]);
             solve(ans,ar,arr,j+1);
             swap(arr[i],arr[j]);
             ar.pop_back();
        }
    }
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        set<vector<int>> ans;
        vector<int> ar;
        set<int> index;
        solve(ans,ar,arr,0);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};