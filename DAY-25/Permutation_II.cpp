class Solution {
    void permute(set<vector<int>>& st,int index,int n,vector<int> nums){
        if(index>=n){
            st.insert(nums);
            return;
        }
        for(int i=index;i<n;i++){
            swap(nums[i],nums[index]);
            permute(st,index+1,n,nums);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       set<vector<int>> st;
       
        permute(st,0,nums.size(),nums);
        vector<vector<int>> result(st.begin(),st.end());
        return result;
    }
};