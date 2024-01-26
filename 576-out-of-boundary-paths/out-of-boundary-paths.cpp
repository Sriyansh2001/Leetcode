class Solution {
public:
    vector<vector<vector<int>>> dp;
    int arr[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int M = 1e9+7;
    int solve(int m,int n,int i,int j,int move) {
        if(i<0 || j<0 || i==m || j==n) {
            return 1;
        }
        if(dp[i][j][move]!=-1) {
            return dp[i][j][move];
        }
        if(move>0) {
            long long ans=0;
            for(auto k:arr) {
                ans += solve(m,n,i+k[0],j+k[1],move-1);
            }
            return dp[i][j][move] = ans%M;
        }
        return 0;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.resize(m,vector<vector<int>> (n,vector<int> (maxMove+1,-1)));
        return solve(m,n,startRow,startColumn,maxMove)%M;
    }
};