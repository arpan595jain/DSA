class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void isSubIsland(int r, int c, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<int>> &visited, bool &flag){
        visited[r][c] = 1;
        int n = grid1.size(), m = grid1[0].size();
        for(int i = 0; i < 4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid2[nr][nc] == 1){
                if(grid1[nr][nc] == 0) flag = false;
                else isSubIsland(nr, nc, grid1, grid2, visited, flag);
            }
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size(), m = grid2[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] == 1 || grid1[i][j] == 0 || grid2[i][j] == 0) continue;
                bool flag = true;
                isSubIsland(i, j, grid1, grid2, visited, flag);
                count += flag;
            }
        }
        return count;
    }
};
