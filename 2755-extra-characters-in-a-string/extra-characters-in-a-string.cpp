class Solution {
public:
    int n;
    vector<int> dp;

    int countExtraCharacter(string &s, unordered_set<string> &dict, int i) {
        if(i >= s.length()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        string subString;
        int res = n-i+1;
        res = min(res,countExtraCharacter(s,dict,i+1)+1);
        for(int j=i ; j<n ; ++j) {
            subString.push_back(s[j]);
            if(dict.find(subString) != dict.end()) {
                res = min(res,countExtraCharacter(s,dict,j+1));
            }
        }
        return dp[i] = res;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        unordered_set<string> dict;
        dp.resize(n+1, -1);
        for(auto dic: dictionary) {
            dict.insert(dic);
        }
        return countExtraCharacter(s,dict,0);
    }
};