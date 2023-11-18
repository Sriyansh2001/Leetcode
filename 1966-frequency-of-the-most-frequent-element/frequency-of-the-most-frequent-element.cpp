class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans = 0,n = nums.size(),j=n-1,curr=0;
        sort(nums.begin(),nums.end());
        for(int i=n-1 ; i>=0 ; --i) {
            while(j>=0 && curr+(nums[i]-nums[j]) <= k) {
                curr += nums[i]-nums[j];
                j-=1;
            }
            ans = max(ans,i-j);
            if(i>0) {
                curr -= (nums[i]-nums[i-1])*(i-j-1);
            } 
        }
        return ans;
    }
};