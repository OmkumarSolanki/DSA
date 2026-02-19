class Solution {
  private:
    void rec(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& ans) {
        vis[node] = true;
        ans.push_back(node);
        for(int i=0; i<adj[node].size(); i++) {
            if( vis[adj[node][i]] == false ) {
                rec( adj[node][i], adj, vis, ans );
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> vis(n, false);
        vector<int> ans;
        rec(0, adj, vis, ans);
        return ans;
        
    }
};