/*
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int rstart=0,rend=m-1,cstart=0,cend=n-1;
        vector<int> ans;
        while(rstart<=rend && cstart<=cend){
            for(int i=cstart;i<=cend;i++){
                 ans.push_back(matrix[rstart][i]);
            }
            rstart++;
            if(rstart>rend){
                break;
            }
            for(int i=rstart;i<=rend;i++){
                 ans.push_back(matrix[i][cend]);
            }
            cend--;
            if(cstart>cend){
                break;
            }
            for(int i=cend;i>=cstart;i--){
                 ans.push_back(matrix[rend][i]);
            }
            rend--;
            if(rstart>rend){
                break;
            }
            for(int i=rend;i>=rstart;i--){
                 ans.push_back(matrix[i][cstart]);
            }
            cstart++;
            if(cstart>cend){
                break;
            }
        }
        return ans;
    }
};*/