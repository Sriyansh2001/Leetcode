class Solution {
    vector<int> dp;
public:
    int solve(vector<int> &nums,int target) {
        if(target < 0) return 0;
        if(dp[target] != -1) return dp[target];
        dp[target] = 0;
        for(int j=0 ; j<nums.size() ; ++j) {
            dp[target] += solve(nums,target-nums[j]);
        }
        return dp[target];
    }
 
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1,-1);
        dp[0]=1;
        return solve(nums,target);
    }
};