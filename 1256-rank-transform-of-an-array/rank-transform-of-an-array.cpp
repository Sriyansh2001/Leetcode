class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        int n = arr.size(),rank = 1;
        vector<int> arr2 = arr, res(n,0);
        sort(arr2.begin(),arr2.end());
        for(int i=0 ; i<n ; ++i) {
            if(mp.find(arr2[i]) == mp.end()) {
                mp[arr2[i]] = rank;
                rank+=1;
            }
        }
        for(int i=0 ; i<n ; ++i) {
            res[i] = mp[arr[i]];
        } 
        return res;
    }
};