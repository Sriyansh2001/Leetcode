class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        long long sum = 0,res = 0;
        int n = nums.size();
        int i=0,j=k-1;
        for(int ind=0 ; ind<k-1 ;  ++ind) {
            mp[nums[ind]]++;
            sum += nums[ind];
        }
        while(j<n) {
            mp[nums[j]]++;
            sum += nums[j];
            if(mp.size() == k) {
                res = max(res,sum);
            }
            sum -= nums[i];
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) {
                mp.erase(nums[i]);
            }
            i++;
            j++;
        }
        return res;
    }
};