class Solution {
public:
    int solve(vector<string> &word,int i,vector<int> &vis) {
        if(vis[i]!=-1) {
            return vis[i];
        }
        int ans = 1;
        string s = word[i];
        for(int j=0 ; j<word.size() ; ++j) {
            if(word[j].size()-1 == s.length()) {
                int k=0;
                for(int st=0 ; st<word[j].length() && k<s.length() ; st+=1) {
                    if(word[j][st] == s[k]) {
                        k+=1;
                    }
                }
                if(k == s.length()) {
                    ans = max(ans,solve(word,j,vis)+1);
                }
            }
        }
        return vis[i] = ans;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> vis(n,-1);
        int ans = 0;
        for(int i=0 ; i<words.size() ; ++i) {
            ans = max(ans,solve(words,i,vis));
        }
        return ans;
    }
};