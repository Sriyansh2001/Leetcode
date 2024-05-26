class Solution {
public:
    int checkRecord(int n) {
        for(int i=0 ; i<100005 ; ++i) {
            for(int j=0 ; j<2 ; ++j) {
                for(int k=0 ; k<4 ; ++k) {
                    dp[i][j][k]=-1;
                }
            }
        }
        return count_total_ways(n,0,0);
    }
private:
    const int M = 1e9+7;
    int dp[100005][2][4];
    long long count_total_ways(int pre_day,int abs,int late) {
        if(pre_day <= 0) {
            return 1;
        }
        if(dp[pre_day][abs][late] != -1) {
            return dp[pre_day][abs][late];
        }
        if(abs<1) {
            if(late>=2)
                return dp[pre_day][abs][late] = (count_total_ways(pre_day-1,abs+1,0)+count_total_ways(pre_day-1,abs,0))%M;
            else
                return dp[pre_day][abs][late] = (count_total_ways(pre_day-1,abs+1,0)+count_total_ways(pre_day-1,abs,0)+count_total_ways(pre_day-1,abs,late+1))%M;
        }
        else {
            if(late>=2) 
                return dp[pre_day][abs][late] = (count_total_ways(pre_day-1,abs,0))%M;
            else
                return dp[pre_day][abs][late] =  (count_total_ways(pre_day-1,abs,0)+count_total_ways(pre_day-1,abs,late+1))%M;
        }   
    }
};