class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0, minutesCount = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = true;
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) 
            return 0;
        
        int countMinutes = -1;
        // because first time in queue will be rotten oranges
        vector<int> xAxis = {0, 1, 0, -1}, yAxis = {1, 0, -1, 0};
    
        while (!q.empty()) {
            int qSize = q.size();
            countMinutes++;
            for (int k = 0; k < qSize; k++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int newX = x + xAxis[i], newY = y + yAxis[i];
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                        grid[newX][newY] == 1 && vis[newX][newY] == false) {
                        q.push({newX, newY});
                        vis[newX][newY] = true;
                        freshCount--;
                    }
                }
            }
        }

        if (freshCount == 0) {
            return countMinutes;
        }
        return -1;
    }
};