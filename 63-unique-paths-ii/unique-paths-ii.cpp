class Solution {
    int n,m;
    vector<vector<int>> dp;
    int dir[2][2] = {{1,0},{0,1}};
public:
    int solve(vector<vector<int>> &obs,int i,int j) {
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(obs[i][j] == 1) return dp[i][j] = 0;
        if(i==n-1 && j==m-1) return dp[i][j] = 1;
        return dp[i][j] = solve(obs,i+dir[0][0],j+dir[0][1])+solve(obs,i+dir[1][0],j+dir[1][1]);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        dp.resize(n,vector<int> (m,-1));
        return solve(obstacleGrid,0,0);
    }
};