class Solution {
    int getminimumValue(vector<int> &nums,int n) {
        int index=0;
        while(index < n-1) {
            int prev = abs(nums[index]);
            int next = abs(nums[index+1]);
            if(prev < next) {
                break;
            }
            index+=1;
        }
        return index;
    }

    vector<int> getresult(vector<int> &nums,int index,int n) {
        vector<int> result;
        int left = index-1, right = index;
        int leftval,rightval;
        while(left >= 0 || right < n) {
            leftval=INT_MAX;
            rightval=INT_MAX;
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
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int index = getminimumValue(nums,n);
        vector<int> result = getresult(nums,index,n);
        return result;
    }
};