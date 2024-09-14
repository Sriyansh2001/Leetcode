class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = 0,maxValue = 0, size = nums.size(), count = 0;

        for(int i=0 ; i<size ; ++i) {
            maxValue = max(maxValue, nums[i]);
        }

        for(int i=0 ; i<size ; ++i) {
            if(maxValue == nums[i]) {
                count += 1;
            } else {
                count = 0;
            }
            len = max(len, count);
        }

        return len;
    }
};