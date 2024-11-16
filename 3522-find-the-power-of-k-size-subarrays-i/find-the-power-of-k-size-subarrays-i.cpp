class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int diff = 0;
        int n = nums.size();
        vector<int> ans;
        int i=0,j=0;
        while(i<k-1) {
            if(nums[i+1]-nums[i] == 1) {
                diff += 1;
            }
            i++;
        }
        if(diff == k-1) {
            ans.push_back(nums[i]);
        } else {
            ans.push_back(-1);
        }
        while(i<n-1) {
            if(nums[j+1]-nums[j] == 1) {
                diff -= 1;
            }
            if(nums[i+1]-nums[i] == 1) {
                diff += 1;
            }
            i++;
            j++;
            if(diff == k-1) {
            ans.push_back(nums[i]);
        } else {
            ans.push_back(-1);
        }
        }
        return ans;
    }
};