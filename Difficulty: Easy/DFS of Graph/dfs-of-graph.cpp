class Solution {
  private:
    void recursion(int node, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& ans) {
        vis[node] = true;
        ans.push_back(node);
        for(int i=0; i<adj[node].size(); i++) {
            if( vis[ adj[node][i] ] == false ) {
                recursion( adj[node][i], vis, adj, ans );
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> vis(n, false);
        vector<int> ans;
        recursion(0, vis, adj, ans);
        return ans;
        
    }
};