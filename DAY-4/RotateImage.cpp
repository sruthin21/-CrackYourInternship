class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int i=0,j=0;
        while(i<n){
            for(int k=j;k<n;k++){
                swap(matrix[i][k],matrix[k][i]);
            }
            j++;
            i++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(matrix[i][j],matrix[i][n-j-1]);
            }
        }
    }
};