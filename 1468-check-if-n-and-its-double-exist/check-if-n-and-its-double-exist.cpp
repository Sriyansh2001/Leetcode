class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        for(auto i:arr) {
            mp[i]+=1;
            if(i == 0) {
                if(mp[i] == 2) {
                    return true;
                }
                continue;
            }
            if(i%2 == 0) {
                if(mp.find(i/2) != mp.end()) {
                    return true;
                }
            }
            if(mp.find(i*2) != mp.end()) {
                return true;
            }
        }
        return false;
    }
};