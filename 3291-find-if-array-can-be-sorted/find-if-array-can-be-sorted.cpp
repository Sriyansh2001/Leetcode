class Solution {
public:
    int calbit(int x) {
        int ans = 0;
        while(x) {
            if(x&1) ans += 1;
            x/=2;
        }
        return ans;
    }

    void bitsort(vector<int> &nums) {
        int n = nums.size();
        for(int i=0 ; i<n ; ++i) {
            for(int j=i-1 ; j>=0 ; --j) {
                if(calbit(nums[j]) == calbit(nums[j+1])) {
                    if(nums[j] > nums[j+1]) {
                        int temp = nums[j];
                        nums[j] = nums[j+1];
                        nums[j+1] = temp;
                    }
                }
                else break;
            }
        }
    }

    bool check_sort(vector<int> &nums) {
        int n = nums.size();
        for(int i=0 ; i<n-1 ; ++i) {
            if(nums[i]>nums[i+1]) {
                return false;
            }
        }
        return true;
    }

    bool canSortArray(vector<int>& nums) {
        bitsort(nums);
        return check_sort(nums);
    }
};