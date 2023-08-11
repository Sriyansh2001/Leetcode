class Solution {
    int amount;
    vector<vector<int>> dp;
public:
    int solve(vector<int> &coins,int i,int sum) {
        if(sum == amount) return 1;
        if(i == coins.size()) return 0;
        if(sum > amount) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum] = solve(coins,i,sum+coins[i])+solve(coins,i+1,sum);
    }

    int change(int amount, vector<int>& coins) {
        this->amount = amount;
        dp.resize(coins.size(),vector<int> (amount,-1));
        return solve(coins,0,0);
    }
};