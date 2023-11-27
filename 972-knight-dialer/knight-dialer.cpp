class Solution {
public:
    vector<vector<int>> move = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
    vector<vector<int>> dp;
    int M = 1e9+7;

    long long solve(int n,int i) {
        if(dp[n][i] != -1) {
            return dp[n][i];
        }
        if(n == 0) {
            return dp[n][i] = 1;
        }
        long long ans = 0;
        for(auto k:move[i]) {
            ans += solve(n-1,k);
            ans %= M;
        }
        return dp[n][i] = ans;
    }

    int knightDialer(int n) {
        long long res = 0;
        dp.resize(n,vector<int> (10,-1));
        for(int i=0 ; i<10 ; ++i) {
            res += solve(n-1,i);
            res %= M;
        }
        return res;
    }
};