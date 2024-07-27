class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int left = 0;
       int right = 1;
       int maxp = 0;
       while(right<prices.size()){
          if(prices[left]<prices[right]){
              maxp = max(maxp,prices[right]-prices[left]);
          }
          else{
             left = right;
          }
          right++;
       }
       return maxp;
    }
};