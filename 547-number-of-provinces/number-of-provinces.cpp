class Solution {
private:
    void bfs(int node, const vector<vector<int>>& adj, vector<bool>& vis) {
        queue<int> q;
        q.push(node);

        while(!q.empty()) {
            int val = q.front();
            q.pop();
            for(int i=0; i<adj[val].size(); i++) {
                if( vis[adj[val][i]] == false ) {
                    q.push( adj[val][i] );
                    vis[adj[val][i]] = true;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n+1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i!=j && isConnected[i][j] == 1 ) {
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int count = 0;
        vector<bool> vis(n+1, false);
        for(int i=1; i<=n; i++) {
            if(vis[i]==false) {
                bfs(i, adj, vis);
                count++;
            }
        }
        return count;
    }
};