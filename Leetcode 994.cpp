class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int>dir = {-1,0,1,0,-1};
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>>q;
        int fresh = 0;
        for(int i=0; i<m; i++){
            for(int j=0;j <n; j++){
                if(grid[i][j] == 2) q.push({i,j}); 
                if(grid[i][j] == 1) fresh++;
            }
        }
        if(fresh == 0) return 0;

        int ans = -1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int>p = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int dx = p.first + dir[i];
                    int dy = p.second + dir[i+1];

                    if(dx >=0 && dx <m && dy>=0 && dy <n && grid[dx][dy] == 1){
                        grid[dx][dy] = 2;
                        q.push({dx,dy});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        if(fresh >0) return -1;
        // if(ans == -1) return 0;
        return ans; 
    }
};
