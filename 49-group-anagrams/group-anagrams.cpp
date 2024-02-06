class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto i:strs) {
            string k = i;
            sort(k.begin(),k.end());
            mp[k].push_back(i);
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