class Solution {
    vector<vector<vector<int>>> dp;
public:
    int solve(vector<int> &houses,vector<vector<int>> &cost,int m,int n,int target,int i,int neg,int prev) {
        if(target < neg) {
            return 1e7;
        }
        if(i>=m) {
            if(neg == target) return 0;
            return 1e7;
        }
        if(dp[i][neg][prev+1] != -1) {
            return dp[i][neg][prev+1];
        }
        if(houses[i] == 0) {
            int ans = INT_MAX;
            for(int j=1 ; j<=n ; ++j) {
                if(j == prev)
                    ans = min(ans,solve(houses,cost,m,n,target,i+1,neg,j)+cost[i][j-1]);
                else
                    ans = min(ans,solve(houses,cost,m,n,target,i+1,neg+1,j)+cost[i][j-1]);
            }
            return dp[i][neg][prev+1] = ans;
        }
        return dp[i][neg][prev+1] = solve(houses,cost,m,n,target,i+1,neg+(prev == houses[i] ? 0 : 1),houses[i]);
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        dp.resize(m+1,vector<vector<int>> (target+1,vector<int> (n+4,-1)));
        int ans = solve(houses,cost,m,n,target,0,0,-1);
        return ans > 1e6 ? -1 : ans;
    }
};