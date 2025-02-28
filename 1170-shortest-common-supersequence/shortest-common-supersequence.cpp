class Solution {
public:
    vector<vector<int>> dp;
    string shortestCommonSupersequence(string text1, string text2) {
        int n = text1.size(),m = text2.size();
        dp.resize(n+1,vector<int> (m+1,-1));
        for(int i=0 ; i<n+1 ; ++i) dp[i][0] = 0;
        for(int i=0 ; i<m+1 ; ++i) dp[0][i] = 0;
        for(int i=1 ; i<=n  ; ++i) {
            for(int j=1 ; j<=m ; ++j) {
                if(text1[i-1]==text2[j-1]) 
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i=n,j=m;
        string ans;
        while(i>0 && j>0) {
            if(text1[i-1]==text2[j-1]) {
                ans.push_back(text1[i-1]);
                i-=1;
                j-=1;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]) {
                    ans.push_back(text1[i-1]);
                    i-=1;
                }
                else{
                    ans.push_back(text2[j-1]);
                    j-=1;
                }
            }
        }
        while(i>0) {ans.push_back(text1[i-1]); i--;}
        while(j>0) {ans.push_back(text2[j-1]); j--;}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};