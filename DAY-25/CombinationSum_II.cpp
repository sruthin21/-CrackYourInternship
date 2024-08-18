class Solution {
    private:
    void fun(vector<vector<int>>& result,vector<int> ans,vector<int> candidate,int target,int index,int length){
        if(target==0 && index<length){
              result.push_back(ans);
              return;
        }
        else if(target<0 || index>=length){
             return;
        }
        ans.push_back(candidate[index]);
        fun(result,ans,candidate,target-candidate[index],index,length);
        ans.pop_back();
        fun(result,ans,candidate,target,index+1,length);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<candidates.size();i++){
            map[candidates[i]]++;
        }
        vector<int> candidate;
        for(auto it:map){
            candidate.push_back(it.first);
        }
        int length = candidate.size();
        sort(candidate.begin(),candidate.end());
        vector<vector<int>> result;
        
        vector<int> ans;
        fun(result,ans,candidate,target,0,length);
        vector<vector<int>> result1;
        for(int i=0;i<result.size();i++){
            unordered_map<int,int> map1;
            int size = result[i].size();
            for(int j=0;j<size;j++){
                map1[result[i][j]]++;
            }
            bool flag = true;
            for(auto it:map1){
                if(map1[it.first]>map[it.first]){
                   flag = false;
                }
            }
            if(flag){
                result1.push_back(result[i]);
            }
        }
        return result1;
    }
};