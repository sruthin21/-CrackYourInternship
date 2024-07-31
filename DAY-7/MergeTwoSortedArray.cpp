class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i1 = 0,j1=nums1.size();
        int i2 = 0,j2=nums2.size();
        while(i1<m && i2<n){
            if(nums1[i1]<nums2[i2]){
                ans.push_back(nums1[i1]);
                i1++;
            }
            else{
                ans.push_back(nums2[i2]);
                i2++;
            }
        }
        while(i1<m){
            ans.push_back(nums1[i1]);
            i1++;
        }
        while(i2<n){
            ans.push_back(nums2[i2]);
            i2++;
        }
        nums1 = ans;
    }
};