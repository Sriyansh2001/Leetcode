class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(),val = 0,res = 0;
        unordered_map<int,int> mp; mp[0]=-1;
        for(int i=0 ; i<n ; ++i) {
            val = val + (nums[i] == 0 ? 1 : -1);
            if(mp.find(val)!=mp.end()) res = max(res,i-mp[val]);
            else mp[val]=i;
        }
        return res;
    }
};