class Solution {
    vector<vector<int>> dp;
public:
    int solve(vector<int> &nums,int target,int level) {
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(dp[level][target] != -1) return dp[level][target];
        int ans = 0;
        for(int j=0 ; j<nums.size() ; ++j) {
            ans += solve(nums,target-nums[j],level+1);
        }
        return dp[level][target] = ans;
    }
 
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1, vector<int> (target+1,-1));
        return solve(nums,target,0);
    }
};