class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[n-1];
        long long res=0;
        for(int i=n-2 ; i>=0 ; --i) {
            if(nums[i]<=mx) {
                mx = nums[i];
                continue; 
            }
            int rem = nums[i]%mx; 
            if(rem == 0) {
                res += (nums[i]/mx - 1);
            }
            else {
                res += (nums[i]/mx);

                int t = nums[i]/mx;
                int k = mx-rem;
                int times = k/(t+1);
                int left = k%(t+1);
                if(left != 0) {
                    mx = rem+(t*times)+left-1;
                }
                else {
                    mx = rem+(t*times);
                }
            }
        }
        return res;
    }
};