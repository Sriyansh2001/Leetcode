class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> freq(n);
        int m = roads.size();
        set<pair<int,int>> check;
        for(int i=0 ; i<m ; ++i) {
            freq[roads[i][0]]+=1;
            freq[roads[i][1]]+=1;
            check.insert({min(roads[i][0],roads[i][1]),max(roads[i][0],roads[i][1])});
        }
        int ans = 0;
        for(int i=0 ; i<n ; ++i) {
            for(int j=0 ; j<i ; ++j) {
                if(check.find({j,i})!=check.end()) {
                    ans = max(ans,freq[i]+freq[j]-1);
                }
                else {
                    ans = max(ans,freq[i]+freq[j]);
                }
            }
        }
        return ans;
    }
};