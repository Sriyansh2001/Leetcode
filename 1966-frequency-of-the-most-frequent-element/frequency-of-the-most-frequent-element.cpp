class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long ans = 0,n = nums.size(),j=0,s1 = 0,s2 = 0,happen,curr,area;
        sort(nums.begin(),nums.end());
        for(int i=0 ; i<n ; ++i) {
            s2 += nums[i];
            happen = true;
            while(happen) {
                happen = false;
                curr = s2-s1;
                area = nums[i]*(i-j+1);
                if(k + curr < area) {
                    happen = true;
                    s1 += nums[j];
                    j+=1;
                }
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};