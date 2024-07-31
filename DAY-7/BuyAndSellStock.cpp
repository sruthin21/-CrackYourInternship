class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> arr(len,0);
        int l = 0;
        int r = 1;
        while(r<len){
            if(prices[l]<prices[r] && prices[r-1]<prices[r]){
                int diff = abs(prices[l]-prices[r]);
                arr[l]=max(arr[l],diff);
            }
            else if(prices[r-1]>prices[r]){
                l = r;
            }
            r++;
        }
        int c =0;
        for(int i=0;i<len;i++){
            c = c+arr[i];
        }
        return c;
    }
}; 