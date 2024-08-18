class Solution {
public:
    void subsets(set<vector<int>> &ans,vector<int> res,int i,int n,vector<int> nums){
        if(i>=n){
            ans.insert(res);
            return;
        }
        res.push_back(nums[i]);
        subsets(ans,res,i+1,n,nums);
        res.pop_back();
        subsets(ans,res,i+1,n,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> res;
        subsets(ans,res,0,nums.size(),nums);
        vector<vector<int>> result(ans.begin(),ans.end());
        return result;
    }
};