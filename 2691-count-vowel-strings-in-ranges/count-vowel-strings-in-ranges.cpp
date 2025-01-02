class Solution {
public:
    bool isVowel(char s) {
        return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pre, ans;
        int n = words.size(),m = queries.size(),l;
        for(int i=0 ; i<n ; ++i) {
            l = words[i].length();
            pre.push_back(isVowel(words[i][0]) && isVowel(words[i][l-1]));
            if(i != 0) {
                pre[i] = pre[i] + pre[i-1];
            }
        }
        for(int i=0 ; i<m ; ++i) {
            int start = queries[i][0];
            int end = queries[i][1];
            if(start != 0)
                ans.push_back(pre[end] - pre[start-1]);
            else
                ans.push_back(pre[end]);
        }
        return ans;
    }
};