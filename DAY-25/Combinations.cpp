class Solution {
    private:
    void comb(vector<vector<int>>& ans,vector<int> temp,vector<int> nums,int index,int k,int count){
        
        if(index>=nums.size() && count<k){
            return;
        }
        if(count==k){
            ans.push_back(temp);
            return;
        }

        for(int i = index;i<nums.size();i++){
            temp.push_back(nums[i]);
            comb(ans,temp,nums,i+1,k,count+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            nums[i]=i+1;
        }
        comb(ans,temp,nums,0,k,0);
        return ans;
    }
};