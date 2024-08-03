class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0;
        int j = height.size()-1;
        int ans =0,area=0;
        while(i<j){
            int n1 = j-i;
            int n2 = 0;
            if(height[i]>height[j]){
                n2 = height[j];
                j--;
            }
            else{
                n2 = height[i];
                i++;
            }
            ans = n1*n2;
            if(ans>area){
                area = ans;
            }
        }
        return area;
    }
};