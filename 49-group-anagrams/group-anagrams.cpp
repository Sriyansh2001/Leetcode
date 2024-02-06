class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        
        for(int i=0 ; i<strs.size() ; ++i) {
            vector<int> t(26,0);
            for(int j=0 ; j<strs[i].length() ; ++j) {
                t[strs[i][j]-'a'] += 1;
            }
            string temp = "";
            for(int j=0 ; j<26 ; ++j) {
                temp.push_back('.');
                string val = to_string(t[j]);
                for(int k=0 ; k<val.length() ; ++k) {
                    temp.push_back(val[k]);
                }
            }
            mp[temp].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto i:mp) {
            vector<string> res;
            for(auto j:i.second) {
                res.push_back(j);
            }
            ans.push_back(res);
        }
        return ans;
    }
};