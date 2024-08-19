class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int index = 0;
        int sum = 0;
        for(int i=0;i<gas.size();i++){
           total +=(gas[i]-cost[i]);
           sum +=(gas[i]-cost[i]);
           if(total<0){
              index = i+1;
              total = 0;
           }
        }
      if(sum<0){
        return -1;
      }
       return index;
    }
};