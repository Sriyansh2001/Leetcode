class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size(),j = s.size()-1;
        int ans = 0;
        for(int i=n-1 ; i>=0 ; --i) {
            if(j<0) return ans;
            if(s[j]>=g[i]) {
                ans += 1;
                j-=1;
            }
        }
        return ans;
    }
};