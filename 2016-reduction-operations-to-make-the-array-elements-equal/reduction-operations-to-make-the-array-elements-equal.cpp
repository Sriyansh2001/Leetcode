class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i=n-1 ; i>=0 ; ) {
            int val = nums[i];
            while(i>=0 && nums[i] == val) {
                i-=1;
            }
            if(i>=0) {
                ans = ans + n-i-1;
            }
        }
        return ans;
    }
};