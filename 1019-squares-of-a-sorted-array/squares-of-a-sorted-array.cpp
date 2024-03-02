class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        while(index < n-1) {
            int prev = abs(nums[index]);
            int next = abs(nums[index+1]);
            if(prev < next) {
                break;
            }
            index+=1;
        }
        int left = index-1, right = index;
        vector<int> result;
        while(left >= 0 || right < n) {
            int leftval=INT_MAX,rightval=INT_MAX;
            if(left >= 0) {
                leftval = nums[left]*nums[left];
            }
            if(right < n) {
                rightval = nums[right]*nums[right];
            }
            if(leftval < rightval) {
                result.push_back(leftval);
                left-=1;
            }
            else {
                result.push_back(rightval);
                right+=1;
            }
        }
        return result;
    }
};