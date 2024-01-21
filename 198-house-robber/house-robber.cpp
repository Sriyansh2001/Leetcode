class Solution {
public:
    vector<int> dp;

    int solve(vector<int> &nums,int i) {
        if(i>=nums.size()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        return dp[i] = max(solve(nums,i+1),solve(nums,i+2)+nums[i]);
    }

    int rob(vector<int>& nums) {
        dp.resize(nums.size()+1,-1);
        return solve(nums,0);
    }
};