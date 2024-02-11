class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>> &grid,int i,int j1,int j2) {
        if(j1 < 0 || j2 < 0 || i>=grid.size() || j1 >= grid[0].size() || j2 >= grid[0].size()) {
            return 0;
        }
        if(dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }
        int ans = 0;
        if(j1 == j2) {
            ans = grid[i][j1];
        }
        else {
            ans = grid[i][j1]+grid[i][j2];
        }
        int res = 0;
        for(int j=-1 ; j<2 ; ++j) {
            for(int k=-1 ; k<2 ; ++k) {
                res = max(res,solve(grid,i+1,j1+j,j2+k));
            }
        }
        return dp[i][j1][j2] = res + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n, vector<vector<int>> (m, vector<int> (m,-1)));      
        return solve(grid,0,0,grid[0].size()-1);
    }
};