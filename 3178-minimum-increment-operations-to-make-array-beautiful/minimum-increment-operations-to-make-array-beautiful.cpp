class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(vector<int> &nums,int k,int i,int com) {
        int n = nums.size();
        if(i>=n) {
            return 0;
        }
        if(dp[i][com] != -1) {
            return dp[i][com];
        }
        
        if(nums[i] >= k) {
            return dp[i][com] = solve(nums,k,i+1,2);
        }
        if(com == 0) {
            return dp[i][com] = solve(nums,k,i+1,2)+(k-nums[i]);
        }
        return dp[i][com] = min(solve(nums,k,i+1,2)+(k-nums[i]),solve(nums,k,i+1,com-1));
    }

    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        dp.resize(n+1,vector<long long> (4,-1));
        return solve(nums,k,0,2);
    }
};