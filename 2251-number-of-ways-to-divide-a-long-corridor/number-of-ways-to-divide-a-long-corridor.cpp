class Solution1 {
    vector<vector<int>> dp;
    int M = 1e9+7;
    int solve(string &s,int i,int time) {
        if(i == s.length()) {
            return time == 2;
        }
        if(dp[i][time] != -1) {
            return dp[i][time];
        }
        long long ans = 0;
        if(time == 0) {
            if(s[i] == 'S') {
                ans =  solve(s,i+1,time+1);
            }
            else {
                ans = solve(s,i+1,time);
            }
        }
        else if(time == 1) {
            if(s[i] == 'S') {
                ans = solve(s,i+1,time+1);
            }
            else {
                ans = solve(s,i+1,time);
            }
        }
        else if(time == 2) {
            if(s[i] == 'S') {
                ans = solve(s,i+1,1);
            }
            else {
                ans = solve(s,i+1,0)+solve(s,i+1,2);
            }
        }
        return dp[i][time] = ans%M;
    }
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        dp.resize(n , vector<int> (3,-1));
        return solve(corridor,0,0);
    }
};

class Solution {
    int M = 1e9+7;
public:
    int numberOfWays(string s) {
        long long res = 1;
        int n = s.size(),i=0,t=0,poss=1;
        while(i<n) {
            if(s[i] == 'S') {
                t+=1;
            }
            if(t == 2) {
                t = 0;
                poss = 0;
                int count = 1;
                i+=1;
                while(i<n && s[i] == 'P') {
                    i+=1;
                    count += 1;
                }
                if(i<n)
                    res = (res * count)%M;
            }
            else {
                i += 1;
            }
        }
        if(t!=0 || poss) return 0;
        return res;
    }
};