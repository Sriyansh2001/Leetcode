class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        map<int,vector<int>> mp;
        int n = nums.size();
        for(int i=0 ; i<nums.size() ; ++i) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto i:mp) {
            int s = i.second[0];
            int f = i.second[0];
            int mx = 0;
            for(int j=1 ; j<i.second.size() ; ++j) {
                f = i.second[j];
                mx = max(mx,abs(i.second[j]-i.second[j-1]-1));
            }
            mx = max(mx,(s+(n-f-1)));
            ans = min(mx,ans);
        }
        return ans%2==0? ans/2 : ans/2+1;
    }
};