class Solution {
    public void islandsAndTreasure(int[][] grid) {
        int INF = Integer.MAX_VALUE;
        int n = grid.length;
        int m = grid[0].length;

        Deque<int[]> q = new ArrayDeque<>();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 0) {
                    q.addLast(new int[]{i, j, 0});
                }
            }
        }

        int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.isEmpty()) {
            int[] p = q.removeFirst();
            int i = p[0], j = p[1], t = p[2];

            if (grid[i][j] < t) continue;

            grid[i][j] = t;

            for (int[] d: dirs) {
                int di = d[0], dj = d[1];
                int ni = i+di, nj = j+dj;

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] != -1) {
                    q.addLast(new int[]{ni, nj, t+1});
                }
            }
        }
    }
}
