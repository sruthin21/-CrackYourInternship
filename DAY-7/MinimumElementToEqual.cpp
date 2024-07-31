class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mid = (nums.size())/2;
        sort(nums.begin(),nums.end());
        if(nums.size()%2==0){
            mid--;
        }
        int num = nums[mid];
        int c = 0;
        for(int i=0;i<nums.size();i++){
            c = c+abs(nums[i]-num);
        }
        return c;
    }
};