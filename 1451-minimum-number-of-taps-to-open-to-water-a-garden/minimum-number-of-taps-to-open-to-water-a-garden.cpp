class Solution {
public:
    int n ,k;
    vector<vector<int>> dp;

    int solve(vector<int> &range,int i,int ind) {
        if(i >= n) {
            if(ind < k) {
                return 1e7;
            }
            return 0;
        }
        if(ind >= k) {
            return 0;
        }
        if(ind+100 < i) {
            return 1e7;
        }
        if(dp[i][i-ind+101] != -1) {
            return dp[i][i-ind+101];
        }
        if(i-range[i] <= ind && range[i]>0) {
            return dp[i][i-ind+101] = min(solve(range,i+1,range[i]+i)+1,solve(range,i+1,ind));
        }
        return dp[i][i-ind+101] = solve(range,i+1,ind);
    }

    int minTaps(int k, vector<int>& ranges) {
        this->k = k;
        n = ranges.size();
        dp.resize(n+1,vector<int> (210,-1));
        int ans = solve(ranges,0,0);
        return ans > 1e6 ? -1 : ans;
    }
};





















