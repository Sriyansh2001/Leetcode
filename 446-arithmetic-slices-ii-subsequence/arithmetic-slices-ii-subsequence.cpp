class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<map<long,int>> mp(n);
        map<int,int> v,k;
        int ans = 0;
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<i ; ++j) {
                long diff = nums[i]-(long)nums[j];
                mp[i][diff] += mp[j][diff] + 1;
                ans += mp[j][diff];
            }
        }
        return ans;
    }
};