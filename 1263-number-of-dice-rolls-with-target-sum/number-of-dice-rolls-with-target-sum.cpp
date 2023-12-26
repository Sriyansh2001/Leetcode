class Solution {
public:
    vector<vector<int>> dp;
    int M = 1e9+7;

    long long solve(int n, int k,int tar) {
        if(tar < 0) {
            return 0;
        }
        if(n == 0 && tar == 0) {
            return 1;
        }
        if(n == 0) {
            return 0;
        }
        if(dp[n][tar] != -1) {
            return dp[n][tar];
        }
        long long ans = 0;
        for(int j=1 ; j<=k ; ++j) {
            ans += solve(n-1,k,tar-j);
        }
        return dp[n][tar] = ans%M;
    }

    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1,vector<int> (target+1,-1));
        return solve(n,k,target);
    }
};