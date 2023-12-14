class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<vector<int>> &g,int ind,int par,int floor,vector<int> &coins,int k) {
        if(dp[ind][floor] != -1) {
            return dp[ind][floor];
        }

        int ans1 = ((coins[ind]/(pow(2,floor))/2));
        int ans2 = (coins[ind]/(pow(2,floor)))-k;
        
        for(auto i:g[ind]) {
            if(i == par) continue;
            
            ans1 += solve(g,i,ind,min(14,floor+1),coins,k);
            ans2 += solve(g,i,ind,floor,coins,k);
        }
        
        return dp[ind][floor] = max(ans1,ans2);
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = edges.size();
        vector<vector<int>> g(n+1);
        dp.resize(n+1,vector<int> (15,-1));

        for(int i=0 ; i<n ; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        
        return solve(g,0,-1,0,coins,k);
    }
};