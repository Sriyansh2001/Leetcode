class Solution {
public:
    int solve(vector<int> &nums,int i,int k,unordered_map<int,int> &mp) {
        if(i==nums.size()) return 1;
        if(mp[nums[i]-k]==0) {
            int res=0;
            mp[nums[i]]+=1;;
            res += solve(nums,i+1,k,mp);
            mp[nums[i]]-=1;
            res += solve(nums,i+1,k,mp);
            return res;
        }
        else {
            return solve(nums,i+1,k,mp);
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());
        return solve(nums,0,k,mp)-1;
    }
};