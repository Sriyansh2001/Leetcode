class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int size = nums.size();
        if(size <= 2) {
            return true;
        }
        for(int i=0 ; i<size-1 ; ++i) {
            if(nums[i]+nums[i+1] >= m) {
                return true;
            }
        }
        return false;
    }
};