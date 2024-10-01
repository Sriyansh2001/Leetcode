class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;
        for(int i=0 ; i<arr.size() ; ++i) {
            if(arr[i] >= 0) {
                mp[arr[i] % k] += 1;
            } else {
                mp[k - (-arr[i] % k)] += 1;
            }
        }
        for(int i=1 ; i<=k/2 ; ++i) {
            if(mp[i] != mp[k-i]) {
                return false;
            }
        }
        if(k%2 == 1) return true;
        return mp[k/2] % 2 == 0;
    }
};