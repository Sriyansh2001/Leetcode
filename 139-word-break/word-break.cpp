class Trie{
public:
    Trie* arr[26];
    bool end;
    Trie() {
        for(int i=0 ; i<26 ; ++i) {
            arr[i] = NULL;
        }
        end = false;
    }
};

class Solution {
public:
    Trie *t;
    vector<vector<int>> dp;

    Solution() {
        t = new Trie();
    }

    void insert(string &s) {
        int n = s.length();
        Trie *t = this->t;
        for(int i=0 ; i<n ; ++i) {
            if(t->arr[s[i]-'a'] == NULL) {
                t->arr[s[i]-'a'] = new Trie();
            }
            t = t->arr[s[i]-'a'];
        }
        t->end = true;
    }

    bool search(string &s,int i,int j,Trie *tree) {
        if(i>=s.length()) {
            return tree->end;
        }
        bool res = false;
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        if(tree->end) {
            res = res || search(s,i,0,t);
        } 
        if(tree->arr[s[i]-'a'] == NULL) {
            return dp[i][j] = res;
        }
        return dp[i][j] = res || search(s,i+1,j+1,tree->arr[s[i]-'a']);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.length(),vector<int> (s.length(),-1));
        for(auto i:wordDict) {
            insert(i);
        }
        return search(s,0,0,t);
    }
};