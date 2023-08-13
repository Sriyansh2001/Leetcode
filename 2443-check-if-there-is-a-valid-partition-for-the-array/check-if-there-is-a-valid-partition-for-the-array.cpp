class Solution {
    int n;
    vector<int> dp;
public:
    bool solve(vector<int> &nums,int i) {
        if(i >= n) {
            return true;
        }
        if(dp[i]!=-1) return dp[i];
        bool ans = false;
        int j=i;
        if(i<n-1 && nums[i] == nums[i+1]) {
            i+=1;
            ans |= solve(nums,i+1);
            if(i<n-1 && nums[i] == nums[i+1]) {
                i+=1;
                ans |= solve(nums,i+1);
            }
        }   
        else {
            if(i<n-2 && nums[i]+1 == nums[i+1] && nums[i+1]+1 == nums[i+2]) {
                return dp[j] = solve(nums,i+3);
            }
        }
        return dp[j] = ans;
    }

    bool validPartition(vector<int>& nums) {
        n = nums.size();
        dp.resize(n,-1);
        return solve(nums,0);
    }
};