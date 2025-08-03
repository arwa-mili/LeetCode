class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    int m,n;
    int dfs(int i, int j) {
        if (i < 0 || j < 0 || i == m || j == n || !grid[i][j]) {
            return 1;
        }
        if (visited[i][j]) return 0;
        visited[i][j] = 1;
        return dfs(i+1, j) + dfs(i-1, j) + dfs(i, j+1) + dfs(i, j-1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();    
        n = grid[0].size();    
        this->grid = grid;
        visited = vector<vector<bool>> (m, vector<bool> (n, false));
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                if (grid[i][j]) {
                    return dfs(i,j);
                }
            }
        }
        return 0;
    }
};