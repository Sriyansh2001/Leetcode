class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums) mp[i]+=1;
        int check=true;
        vector<vector<int>> ans;
        while(check) {
            vector<int> temp;
            check = false;
            for(auto i:mp) {
                if(i.second>0) {
                    mp[i.first]-=1;
                    temp.push_back(i.first);
                    check=true;
                }
            }
            if(temp.size()>0) ans.push_back(temp);
        } return ans;
    }
};