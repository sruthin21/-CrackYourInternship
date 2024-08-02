class Solution {
    private:
      void bfs(vector<int> adj[],int s,bool visited[],vector<int>& ans){
          visited[s]=true;
          queue<int> q;
          q.push(s);
          while(!q.empty()){
              int u = q.front();
              q.pop();
              ans.push_back(u);
              for(int v:adj[u]){
                  if(visited[v]==false){
                      q.push(v);
                      visited[v]=true;
                  }
              }
          }
      }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
           vector<int> ans;
           bool visited[V];
           for(int i=0;i<V;i++){
               visited[i]=false;
           }
           bfs(adj,0,visited,ans);
           return ans;
    }
}; 