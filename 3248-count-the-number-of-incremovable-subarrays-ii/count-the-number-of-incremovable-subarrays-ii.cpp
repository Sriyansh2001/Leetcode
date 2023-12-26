class Solution {
public:
    int bs1(vector<int> &nums,int tar,int last) {
        int i=0,j=last;
        int ans = -1;
        while(i<=j) {
            int mid = (i+j)/2;
            if(nums[mid] < tar) {
                ans = mid;
                i = mid+1;
            }
            else {
                j = mid-1;
            }
        }
        return ans;
    }

    int bs2(vector<int> &nums,int tar,int start) {
        int i=start,j=nums.size()-1;
        int ans = nums.size()-1;
        while(i<=j) {
            int mid = (i+j)/2;
            if(nums[mid] > tar) {
                ans = mid;
                j = mid-1;
            }
            else {
                i = mid+1;
            }
        }
        return ans;
    }

    long long incremovableSubarrayCount(vector<int>& nums) {
        int inc = 0;
        int n = nums.size();
        int dec = n-1;
        for(int i=1 ; i<n ; ++i) {
            if(nums[i-1]<nums[i]) {
                inc = i;
            } else break;
        }
        for(int i=n-2 ; i>=0 ; --i) {
            if(nums[i] < nums[i+1]) {
                dec = i;
            } else break;
        }

        if(inc >= dec) {
            return (n*1LL*(n+1))/2;
        }

        long long ans = 0;
        
        for(int i=dec ; i<n ; ++i) {
            ans += (bs1(nums,nums[i],inc)+2);
        }

        ans += (inc+1)+1;

        return ans;
    }
};