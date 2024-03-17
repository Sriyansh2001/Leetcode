class Solution {
public:
    int M = 1e9+7,n;
    vector<vector<vector<int>>> v;

    int bin_expo(int a,int b) {
        int ans = 1;
        while(b) {
            if(b&1) {
                ans = (ans*1LL*a)%M;
            }
            a = (a*1LL*a)%M;
            b >>= 1;
        }
        return ans;
    }

    long long solve(vector<int> &nums,int i,int k,int count) {
        if(k < 0) {
            return 0;
        }
        if(v[i][k][count] != -1) {
            return v[i][k][count];
        }
        if(k == 0) {
            return bin_expo(2,n-count);
        }
        if(i == nums.size()) {
            return 0;
        }
        return v[i][k][count] = (solve(nums,i+1,k-nums[i],count+1)+solve(nums,i+1,k,count))%M;
    }

    int sumOfPower(vector<int>& nums, int k) {
        vector<int> num;
        n = nums.size();
        v.resize(101,vector<vector<int>> (101, vector<int> (101,-1))); 
        return solve(nums,0,k,0);
    }
};