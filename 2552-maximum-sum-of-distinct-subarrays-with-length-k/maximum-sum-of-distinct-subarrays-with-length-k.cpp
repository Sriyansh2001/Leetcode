class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        int i=0,j=0,size = nums.size();
        long long res=0,sum=0;
        while(j<size) {
            while(s.find(nums[j])!=s.end()) {
                s.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            sum+=nums[j];
            s.insert(nums[j]);
            if(s.size() == k) {
                res = max(res,sum);
                sum-=nums[i];
                s.erase(nums[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};