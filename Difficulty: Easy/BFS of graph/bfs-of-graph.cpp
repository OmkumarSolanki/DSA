class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        queue<int> q;
        vector<bool> vis(n, false);
        vector<int> ans;
        
        q.push(0);
        vis[0] = true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0; i<adj[node].size(); i++) {
                if( vis[ adj[node][i] ] == false ) {
                    q.push(adj[node][i]);
                    vis[ adj[node][i] ] = true;
                }
            }
        }
        
        return ans;
        
    }
};