class Solution {
    int countSetBit(int num) {
        int count = 0;
        for(int i=0 ; i<31 ; ++i) {
            if((num >> i) & 1) {
                count += 1;
            }
        }
        return count;
    }

public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int prevNumSetBit = -1;
        int currentMin = INT_MAX, currentMax = INT_MIN, prevMax = INT_MIN;
        for(int i=0 ; i<n ; ++i) {
            int setBits = countSetBit(nums[i]);
            if(setBits == prevNumSetBit || prevNumSetBit == -1) {
                // logic to continue computation.
                currentMin = min(currentMin, nums[i]);
                currentMax = max(currentMax, nums[i]);
            } else {
                if(prevMax > currentMin) {
                    return false;
                }
                prevMax = currentMax;
                currentMin = INT_MAX;
                currentMax = INT_MIN;
                i-=1;
            }
            prevNumSetBit = setBits;
        }
        if(prevMax > currentMin) return false;
        return true;
    }
};