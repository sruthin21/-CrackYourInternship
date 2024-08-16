class Solution {
    private:
    void bfs(vector<vector<char>>& grid, vector<vector<int>> &vis,int i,int j,int n,int m){
        vis[i][j]=1;
        int x[4]={1,0,-1,0};
        int y[4]={0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int r = row+x[i];
                int c = col+y[i];
                if(r>=0 && r<n && c>=0 && c<m && grid[r][c]=='1' && vis[r][c]==0){
                    vis[r][c]=1;
                    q.push({r,c});
                }
            }
        }
        
    } 
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                     bfs(grid,vis,i,j,n,m);
                     count++;
                }
            }
        }
        return count;
    }
};