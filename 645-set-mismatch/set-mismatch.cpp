class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(2);
        vector<int> temp(n+1,0);
        for(int i=0 ; i<n ; ++i) {
            temp[nums[i]]+=1;
        }
        for(int i=1 ; i<=n ; ++i) {
            if(temp[i]==0) ans[1] = i;
            if(temp[i]==2) ans[0] = i;
        }
        return ans;
    }
};