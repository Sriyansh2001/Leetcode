class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(),m = l.size();
        vector<bool> ans;
        for(int i=0 ; i<m ; ++i) {
            vector<int> res;
            bool add = true;
            for(int j=l[i] ; j<=r[i] ; ++j) {
                res.push_back(nums[j]);
            }
            sort(res.begin(),res.end());
            int size = res.size();
            if(size == 1) {
                ans.push_back(false);
                continue;
            }
            int k = res[1]-res[0];
            for(int j=0 ; j<size-1 ; ++j) {
                if(res[j+1]-res[j] != k) {
                    add = false;
                    break;
                }
            }
            ans.push_back(add);
        }
        return ans;
    }
};