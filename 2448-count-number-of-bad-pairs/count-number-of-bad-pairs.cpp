class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int> mp;
        long long ans = 0, n = nums.size();
        for(int i=0 ; i<n ; ++i) {
            ans += i - mp[nums[i]-i];
            mp[nums[i]-i]++;
        }
        return ans;
    }
};