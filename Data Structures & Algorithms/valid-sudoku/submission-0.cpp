class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        vector<set<int>> v(n);

        // check for down
        for (int j=0; j<n; j++) {
            for (int i=0; i<n; i++) {
                if (board[i][j] > '0') {
                    int d = board[i][j] - '0';
                    if (v[j].count(d)) {
                        return false;
                    }
                    v[j].insert(d);
                }
            }
            v[j].clear();
        }

        // check for right
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] > '0') {
                    int d = board[i][j] - '0';
                    if (v[i].count(d)) {
                        return false;
                    }
                    v[i].insert(d);
                }
            }
            v[i].clear();
        }

        // check 3x3
        for (int i=0; i<n; i+=3) {
            for (int j=0; j<n; j+=3) {
                set<int> st;
                for (int x=i; x<i+3; x++) {
                    for (int y=j; y<j+3; y++) {
                        if (board[x][y] > '0') {
                            int d = board[x][y];
                            if (st.count(d)) {
                                return false;
                            }
                            st.insert(d);
                        }
                    }
                }
            }
        }

        return true;
    }
};
