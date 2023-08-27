class Solution {
    map<int,int> mp;
    int n;
    vector<vector<int>> dp;
public:
    int solve(vector<int> &stones,int curr,int prev) {
        if(curr >= n-1) return true;
        bool ans = false;
        if(dp[curr][prev] != -1) {
            return dp[curr][prev];
        }
        int jump1 = stones[curr]-stones[prev]-1;
        int jump2 = stones[curr]-stones[prev]+1;
        int jump3 = stones[curr]-stones[prev];
        if(jump1>0 && mp.count(stones[curr]+jump1)) {
            ans = solve(stones,mp[stones[curr]+jump1],curr);
        }
        if(mp.count(stones[curr]+jump2)) {
            ans |= solve(stones,mp[stones[curr]+jump2],curr);
        }
        if(mp.count(stones[curr]+jump3)) {
            ans |= solve(stones,mp[stones[curr]+jump3],curr);
        }
        return dp[curr][prev] = ans;
    }

    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        n = stones.size();
        dp.resize(n,vector<int> (n,-1));
        for(int i=0 ; i<n ; ++i) {
            mp[stones[i]] = i;
        }
        return solve(stones,1,0);
    }
};