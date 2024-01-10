class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int i=1;
        int ans = 0;
        while(i<n) {
            int diff = nums[i]-nums[i-1];
            int count = 0;
            while(i<n && nums[i]-nums[i-1] == diff) {
                count += 1;
                i++;
            }
            ans += (count*(count-1))/2;
        }
        return ans;
    }
};