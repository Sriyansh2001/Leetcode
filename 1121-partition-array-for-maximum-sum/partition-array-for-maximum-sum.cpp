class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &arr,int i,int k,int len,int mx) {
        if(i==arr.size()) return 0;
        if(dp[i][len]!=-1) return dp[i][len];
        int not_partition=0;
        if(len<k)
            not_partition = solve(arr,i+1,k,len+1,max(mx,arr[i]));
        int partition = solve(arr,i+1,k,1,0)+max(mx,arr[i])*len;
        return dp[i][len] = max(partition,not_partition);
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size()+1,vector<int> (k+1,-1));
        return solve(arr,0,k,1,0);
    }
};