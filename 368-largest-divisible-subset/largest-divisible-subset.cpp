class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n+1,0);
        int maxi = 0;
        for(int i=0 ; i<n ; ++i) {
            for(int j=i ; j>=0 ; --j) {
                if(nums[i]%nums[j] == 0) {
                    dp[i] = max(dp[j]+1,dp[i]);
                    maxi = max(dp[i],maxi);
                }
            }
        }
        vector<int> ans;
        int prev = -1;
        for(int i=n-1 ; i>=0 ; --i) {
            if(dp[i] == maxi) {
                if(prev == -1) {
                    ans.push_back(nums[i]);
                    prev = nums[i];
                    maxi -= 1;
                }
                else {
                    if(prev % nums[i] == 0) {
                        maxi -= 1;
                        ans.push_back(nums[i]);
                        prev = nums[i];
                    }
                }
            }
        }
        return ans;
    }
};