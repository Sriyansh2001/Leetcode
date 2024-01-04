class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums) {
            mp[i] += 1;
        }
        int ans = 0;
        for(auto i:mp) {
            int value = i.second;
            if(value == 1) return -1;
            if(value % 3 == 0) {
                ans += value/3;
            }
            else {
                ans += value/3 + 1;
            }
        }
        return ans;
    }
};