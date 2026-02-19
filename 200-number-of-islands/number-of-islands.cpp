class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) 
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> x_dir = {0, 1, 0, -1};
        vector<int> y_dir = {1, 0, -1, 0}; 
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int numIsland = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='1' && vis[i][j] == false) {
                    numIsland++;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for(int k=0; k<4; k++) {
                            int newX = x + x_dir[k], newY = y + y_dir[k];
                            if( newX >=0 && newX < n && newY >=0 && newY < m && grid[newX][newY] == '1' && vis[newX][newY]==false) {
                                q.push({newX, newY});
                                vis[newX][newY] = true;
                            }
                        }
                    }
                }
            }
        }

        return numIsland;
    }
};

// TC -
// SC -