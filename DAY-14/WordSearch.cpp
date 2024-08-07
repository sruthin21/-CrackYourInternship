class Solution {
    private:
    bool check(string &word,vector<vector<char>> &board,int i,int j,int m,int n,int p){
        
         if (p >= word.size()) {
            return true;
        }
        if(board[i][j]=='*') return false;
        if (board[i][j] != word[p]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j]='*';
        
        int x[4] = {-1,0,1,0};
        int y[4] = {0,1,0,-1};
        bool flag = false;
            for(int k=0;k<4;k++){
                int newi = i+x[k];
                int newj = j+y[k];
                if(newi>=0 && newi<n && newj>=0 && newj<m){
                    if(check(word,board,newi,newj,m,n,p+1)){
                        flag = true;
                    }
                }
            }
        board[i][j]=temp;
        return flag;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool flag = false;
        int n = board.size();
        int m = board[0].size();
        int l = word.length();
        if(l==1 && n==1 && m==1 && board[0][0]==word[0]) return true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j] && check(word,board,i,j,m,n,0)){
                    return true;
                }
            }
        }
        return false;
    }
};