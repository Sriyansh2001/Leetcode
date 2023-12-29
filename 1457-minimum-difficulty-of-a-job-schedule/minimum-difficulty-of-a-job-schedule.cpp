class Solution {
public:
    int dp[301][11];

    int solve(vector<int> &job,int i,int d) {
        if(i >= job.size()) {
            if(d == 0) return 0;
            else return 1e7;
        } 
        if(d < 0) {
            return 1e7;
        }
        if(dp[i][d] != -1) {
            return dp[i][d];
        }
        int ans = INT_MAX,mx = 0;
        for(int j=i ; j<job.size() ; ++j) {
            mx = max(job[j],mx);
            ans = min(ans,mx+solve(job,j+1,d-1));
        }
        return dp[i][d] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        for(int i=0 ; i<301 ; ++i) {
            for(int j=0 ; j<11 ; ++j) {
                dp[i][j] = -1;
            }
        }
        int ans = solve(jobDifficulty,0,d);
        if(ans>1e6) {
            return -1;
        }
        return ans;
    }
};