class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        for(int i=0 ; i<n ; ++i) {
            if(nums[i]%modulo == k) {
                nums[i] = 1;
            }
            else{
                nums[i] = 0;
            }
        }
        long ans = 0;
        map<int,int> mp;
        mp[0]=1;
        int val=0;
        for(int i=0 ; i<n ; ++i) {
            val = (val+nums[i])%modulo;
            int curr = ((val+modulo)-k)%modulo;
            ans += mp[curr];
            mp[val]+=1;
        }
        return ans;
    }
};