class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
       vector<vector<int>> ans(board.size(),vector<int>(board[0].size(),0));
       int x[8] = {-1,-1,-1,0,0,1,1,1};
       int y[8] = {-1,0,1,-1,1,-1,0,1};
       for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
           if(board[i][j]==1){
               int live =0;
               for(int k=0;k<8;k++){
                  int i1 = x[k]+i;
                  int j1 = y[k]+j;
                  if(i1>=0 && i1<board.size() && j1>=0 && j1<board[0].size()){
                     if(board[i1][j1]==1){
                        live++;
                     }
                  }
               }
               if(live<2 || live>3){
                ans[i][j]=0;
               }
               else{
                ans[i][j]=1;
               }
           }
           else{
             int live =0;
               for(int k=0;k<8;k++){
                  int i1 = x[k]+i;
                  int j1 = y[k]+j;
                  if(i1>=0 && i1<board.size() && j1>=0 && j1<board[0].size()){
                     if(board[i1][j1]==1){
                        live++;
                     }
                  }
               }
               if(live==3){
                ans[i][j]=1;
               }
               else{
                ans[i][j]=0;
               }
           }
        }
       }
       for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            board[i][j]=ans[i][j];
        }
       }

    }
};