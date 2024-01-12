class Solution {
public:
    vector<int> dp;

    int solve(int x,int y) {
        if(x == y) {
            return 0;
        }
        if(dp[x] != -1) {
            return dp[x];
        }
        if(x > y) {
            int ans = 1e6+7;
            if(x%11 == 0) {
                ans = min(ans,solve(x/11,y)+1);
            }
            else {
                int k = x%11;
                ans = min(ans,solve(x/11 + 1,y)+1+(11-k));
            }
            if(x%5 == 0) {
                ans = min(ans,solve(x/5,y)+1);
            }
            else {
                int k = x%5;
                ans = min(ans,solve(x/5 + 1,y)+1+(5-k));
            }
            ans = min(ans,solve(x-1,y)+1);
            return dp[x] = ans;
        }
        else {
            return dp[x] = solve(x+1,y)+1;
        }
    }

    int minimumOperationsToMakeEqual(int x, int y) {
        dp.resize(1e5+1,-1);
        return solve(x,y);
    }
};