class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int n = values.size();
        int m = values[0].size();
        int mn,val;
        long long d = 1,ans=0;
        vector<int> v(n,m-1);
        
        for(int j=0 ; j<m*n ; ++j) {
            mn = -1,val=INT_MAX;
            for(int i=0 ; i<n ; ++i) {
                if(v[i]>=0 && val > values[i][v[i]]) {
                    mn = i;
                    val = values[i][v[i]];
                }
            }
            v[mn]-=1;
            ans = ans + d * val;
            d+=1;
        }

        return ans;
    }
};