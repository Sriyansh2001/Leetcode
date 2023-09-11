class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        int n = groupSizes.size();
        map<int,vector<int>> mp;
        for(int i=0 ; i<n ; ++i) {
            mp[groupSizes[i]].push_back(i);
        }
        for(auto i:mp) {
            int k = i.first;
            vector<int> res;
            for(auto j:i.second) {
                if(k == 0) {
                    k = i.first;
                    ans.push_back(res);
                    while(res.size()) res.pop_back();
                }
                res.push_back(j);
                k-=1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};