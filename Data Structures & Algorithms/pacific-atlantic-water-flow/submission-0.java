class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int n = heights.length;
        int m = heights[0].length;
        int[][] pacific = new int[n][m];
        int[][] atlantic = new int[n][m];

        Deque<Pair> dq = new ArrayDeque<>();
        // top row
        for (int j=0; j<m; j++) {
            dq.push(new Pair(0, j));
        }
        // left column
        for (int i=0; i<n; i++) {
            dq.push(new Pair(i, 0));
        }

        boolean[][] vis = new boolean[n][m];
        Pair[] dirs = {new Pair(0, 1), new Pair(1, 0), new Pair(0, -1), new Pair(-1, 0)};
        while (!dq.isEmpty()) {
            Pair p = dq.removeLast();
            
            pacific[p.x][p.y] = 1;

            for (Pair d: dirs) {
                int nx = p.x+d.x;
                int ny = p.y+d.y;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && heights[nx][ny] >= heights[p.x][p.y] && !vis[nx][ny]) {
                    dq.push(new Pair(nx, ny));
                    vis[nx][ny] = true;
                }
            }
        }

        // bottom row
        for (int j=0; j<m; j++) {
            dq.push(new Pair(n-1, j));
        }
        // right column
        for (int i=0; i<n; i++) {
            dq.push(new Pair(i, m-1));
        }

        vis = new boolean[n][m];
        while (!dq.isEmpty()) {
            Pair p = dq.removeLast();
            
            atlantic[p.x][p.y] = 1;

            for (Pair d: dirs) {
                int nx = p.x+d.x;
                int ny = p.y+d.y;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && heights[nx][ny] >= heights[p.x][p.y] && !vis[nx][ny]) {
                    dq.push(new Pair(nx, ny));
                    vis[nx][ny] = true;
                }
            }
        }

        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (pacific[i][j] > 0 && atlantic[i][j] > 0) {
                    ans.add(new ArrayList<>());
                    ans.getLast().add(i);
                    ans.getLast().add(j);
                }
            }
        }
        return ans;
    }
}

class Pair {
    int x, y;
    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
