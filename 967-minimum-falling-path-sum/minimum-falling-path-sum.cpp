class Solution {
public:
    vector<vector<int>> dp;
    bool valid(vector<vector<int>> &mat,int j) {
        if(j<0 || j>=mat[0].size()) return false;
        return true;
    }

    bool lastnode(vector<vector<int>> &mat,int i) {
        if(i>=mat.size()) return true;
        return false;
    }

    int solve(vector<vector<int>> &mat,int i,int j) {
        if(lastnode(mat,i)) return 0;
        if(!valid(mat,j)) return 1e7+1;
        if(dp[i][j]!=-101) return dp[i][j];
        return dp[i][j] =  min(solve(mat,i+1,j+1),min(solve(mat,i+1,j),solve(mat,i+1,j-1)))+mat[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        dp.resize(matrix.size(),vector<int> (matrix[0].size(),-101));
        for(int i=0 ; i<matrix[0].size() ; ++i) {
            ans = min(ans,solve(matrix,0,i));
        }
        return ans;
    }
};