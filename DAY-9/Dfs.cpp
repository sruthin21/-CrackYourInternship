class Solution {
    private:
    void dfs(int s,vector<int> adj[], vector<int>& ans,vector<int>& vis){
        vis[s]=1;
        ans.push_back(s);
        for(auto it:adj[s]){
            if(vis[it]==0){
                 dfs(it,adj,ans,vis);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,adj,ans,vis);
            }
        }
        return ans;
    }
};