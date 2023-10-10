class Solution {
    int bs(vector<int> &nums,int tar,int cur) {
        int i=0,j=nums.size()-1;
        int ans = cur;
        while(i<=j) {
            int mid = (i+j)/2;
            if(nums[mid] <= tar) {
                ans = mid;
                i = mid+1;
            }
            else {
                j = mid-1;
            }
        }
        return ans;
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(auto i:nums) {
            mp[i]+=1;
        }
        vector<int> num;
        for(auto i:mp) {
            num.push_back(i.first);
        }
        int extra = n-mp.size();
        int ans = INT_MAX;
        n = num.size();
        for(int i=0 ; i<n ; ++i) {
            ans = min(ans,(n-bs(num,num[i]+(nums.size())-1,i)-1)+(i));
        }
        return ans+extra;
    }
};