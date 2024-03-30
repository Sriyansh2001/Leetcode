class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int z) {
        map<int,int> mp1,mp2;
        int i=0,j=0,k=0,n=nums.size(),ans=0,mx=0;
        while(j<n) {
            mp1[nums[j]]+=1;
            mp2[nums[j]]+=1;
            while(mp1.size()>z) {
                mp1[nums[i]]-=1;
                if(mp1[nums[i]]==0) mp1.erase(nums[i]);
                i+=1;
            }
            while((mp2[nums[k]]>1 && mp2.size()==z) ||  mp2.size()>z) {
                mp2[nums[k]]-=1;
                if(mp2[nums[k]]==0) mp2.erase(nums[k]);
                k+=1;
            }
            if(mp1.size()==z) {
                ans = ans + (k-i+1);
            }
            j+=1;
        } 
        return ans;
    }
};