class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size(),add,curr,val=0;
        long ans = 0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0 ; i<n ; ++i) {
            add = nums[i]%modulo == k ? 1 : 0;
            val = (val+add)%modulo;
            curr = ((val+modulo)-k)%modulo;
            ans += mp[curr];
            mp[val]+=1;
        }
        return ans;
    }
};