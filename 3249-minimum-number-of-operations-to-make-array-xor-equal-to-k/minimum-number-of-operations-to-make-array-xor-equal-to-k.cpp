class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int a = 0;
        int n = nums.size();
        for(int i=0 ; i<n ; ++i) {
            a ^= nums[i];
        }
        int diff = 0;
        while(a) {
            if((a&1) != (k&1)) {
                diff+=1;
            }
            a/=2;
            k/=2;
        }
        while(a || k) {
            if((a&1) || (k&1)) {
                diff += 1;
            }
            a/=2;
            k/=2;
        }
        return diff;
    }
};