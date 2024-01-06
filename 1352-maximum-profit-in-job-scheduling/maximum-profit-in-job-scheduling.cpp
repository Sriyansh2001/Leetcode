class Solution {
public:
    int bs(vector<vector<int>> &v,int end,int tar) {
        int i=0,j=end;
        int ans = -1;
        while(i<=j) {
            int mid = (i+j)/2;
            if(v[mid][0] <= tar) {
                ans = mid;
                i = mid+1;
            }
            else {
                j = mid-1;
            }
        }
        return ans;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        int n = startTime.size();
        for(int i=0 ; i<n ; ++i) {
            v.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(v.begin(),v.end());
        vector<int> ans(n,0);
        ans[0] = v[0][2];
        int res = ans[0];
        for(int i=1 ; i<n ; ++i) {
            int ind = bs(v,i-1,v[i][1]);
            if(ind == -1) {
                ans[i] = max(ans[i-1],v[i][2]);
            }
            else {
                ans[i] = max(ans[i-1],v[i][2]+ans[ind]);
            }
            res = max(res,ans[i]);
        }
        return res;
    }
};