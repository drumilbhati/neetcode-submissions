class Solution {
    int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n, m;
    public int numIslands(char[][] grid) {
        n = grid.length;
        m = grid[0].length;

        int ans = 0;
        boolean[][] vis = new boolean[n][m];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j, vis);
                }
            }
        }
        return ans;
    }

    void dfs(char[][] grid, int i, int j, boolean[][] vis) {
        vis[i][j] = true;
        for (int[] d: dirs) {
            int di = d[0], dj = d[1];
            int ni = i+di, nj = j+dj;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && grid[ni][nj] == '1') {
                dfs(grid, ni, nj, vis);
            }
        }        
    }
}
