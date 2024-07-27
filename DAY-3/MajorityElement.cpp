class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int c = 1;
        for(int i=1;i<nums.size();i++){
            if(num == nums[i]){
                c++;
            }
            else if(num != nums[i]){
                c--;
                if(c<0){
                    num = nums[i];
                    c=1;
                }
            }
        }
        return num;
    }
};