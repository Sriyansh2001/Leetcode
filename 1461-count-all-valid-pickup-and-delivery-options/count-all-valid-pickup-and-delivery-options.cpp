class Solution {
    vector<vector<int>> dp;
    int M = 1e9+7;
public:
    long long solve(int rem,int des) {
        long long ans = 0;
        bool val = 1;

        if(dp[rem][des] != -1) return dp[rem][des];

        ans = rem > 0 ? (ans + solve(rem-1,des+1)*rem)%M : ans;
        ans = des>0 ? (ans + solve(rem,des-1)*des)%M : ans;

        if(rem == 0 && des == 0) {
            return dp[rem][des] = 1;
        }
        return dp[rem][des] = ans%M;
    }

    int countOrders(int n) {
        dp.resize(n+1,vector<int> (n+1,-1));
        return solve(n,0);
    }
};