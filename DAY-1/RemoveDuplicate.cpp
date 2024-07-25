class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 1;
        }

        int i=0;
        int j=1;
        while(i<nums.size()-1){
            if(nums[i]!=nums[i+1]){
                nums[j]=nums[i+1];
                i++;
                j++;
            }
            else{
               i++;
            }
        }
        return j;
    }
};