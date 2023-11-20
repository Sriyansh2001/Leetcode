class Solution {
public:
    int M = 1e9+7;
    vector<vector<vector<int>>> dp;

    long long solve(int n,int d,int s) {
        if(n == 0) {
            return d == 0 && s == 0;
        }
        long long ans = 0;
        if(dp[n][d][s] != -1) {
            return dp[n][d][s];
        }
        if(d) {
            ans += solve(n-1,d-1,s+1);
        }
        if(s) {
            ans += s*solve(n-1,d,s-1);
        }
        if(d && s) {
            ans += solve(n-1,d,s)*(25-s);
        }
        else if(d) {
            ans += solve(n-1,d,s)*25;
        }
        else if(s) {
            ans += solve(n-1,d,s)*(26-s);
        }
        else {
            ans += solve(n-1,d,s)*26;
        }
        return dp[n][d][s] = ans%M;
    } 

    int stringCount(int n) {
        dp.resize(n+1,vector<vector<int>> (3,vector<int> (4,-1)));
        return solve(n,1,2);
    }
};