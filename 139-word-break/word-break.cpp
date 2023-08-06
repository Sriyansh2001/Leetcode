class Solution {
public:
    vector<int> dp;
    set<string> st;
    bool solve(string &s,int i) {
        if(i == s.length()) {
            return true;
        }
        if(dp[i]!=-1) {
            return dp[i];
        }
        string t="";
        bool res = false;
        for(int k=i ; k<min((int)s.length(),i+21) ; k++) {
            t.push_back(s[k]);
            if(st.find(t)!=st.end()) {
                res |= solve(s,k+1);
            }
        }
        return dp[i] = res;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto i:wordDict) {
            st.insert(i);
        }
        dp.resize(s.length()+1,-1);
        return solve(s,0);
    }
};