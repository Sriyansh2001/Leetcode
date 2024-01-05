class Solution {
public:
    int bs(vector<int> &v,int tar) {
        int ans = 0;
        int i=0,j=v.size()-1;
        while(i<=j) {
            int mid = (i+j)/2;
            if(v[mid] >= tar) {
                ans = mid;
                j = mid-1;
            }
            else {
                i = mid+1;
            }
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        int j=0;
        res.push_back(nums[0]);
        for(int i=1 ; i<nums.size() ; ++i) {
            if(res[j] < nums[i]) {
                res.push_back(nums[i]);
                j+=1;
            }
            else {
                int k = bs(res,nums[i]);
                res[k] = nums[i];
            }
        }
        return res.size();
    }
};