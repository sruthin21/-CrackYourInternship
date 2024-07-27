class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i =0;
        while(i<nums.size()){
            if(nums[i]==0){
                break;
            }
            i++;
        }
        int j = i+1;
        while(j<nums.size()){
            if(nums[j]==0){
                j++;
            }
            else{
              swap(nums[i],nums[j]);
              i++;
              j++;
            }
        }
    }
};