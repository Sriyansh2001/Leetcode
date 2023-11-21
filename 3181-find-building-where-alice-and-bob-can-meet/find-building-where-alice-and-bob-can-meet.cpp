class Solution {
public:
    int bs(vector<int> &heights,vector<int> &v,int tar) {
        int i=0,j=v.size()-1;
        int ans = -1;
        while(i<=j) {
            int mid = (i+j)/2;
            if(heights[v[mid]] > tar) {
                ans = v[mid];
                i = mid+1;
            }
            else {
                j = mid-1;
            }
        }
        return ans;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        map<int,vector<vector<int>>> mp;
        vector<int> st;
        int n = queries.size(); 
        for(int i=0 ; i<n ; ++i) {
            int mn = min(queries[i][1],queries[i][0]);
            int mx = max(queries[i][1],queries[i][0]);
            mp[mx].push_back({mn,i});
        }
        vector<int> ans(n);
        n = heights.size();
        for(int i=n-1 ; i>=0 ; --i) {
            while(st.size() && heights[i] >= heights[st[st.size()-1]]) {
                st.pop_back();
            }
            st.push_back(i);
            for(auto j:mp[i]) {
                if(heights[j[0]] < heights[i] || j[0] == i) {
                    ans[j[1]] = i;
                }
                else {
                    ans[j[1]] = bs(heights,st,heights[j[0]]);
                }
            }
        }
        return ans;
    }
};