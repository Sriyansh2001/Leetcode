class Solution {
public:
    int getMax(vector<int> &arr) {
        int maxi = 0;
        for(auto i : arr) maxi = max(maxi, i);
        return maxi;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxi = getMax(nums);
        long long count = 0, res = 0;
        long long i = 0, j = 0, n = nums.size();

        while(j < n) {
            count += nums[j] == maxi;
            while(count >= k) {
                count -= nums[i++] == maxi;
            }
            res += j - i +1;
            j++;
        }

        return ((n * (n+1)) / 2) - res;
    }
};