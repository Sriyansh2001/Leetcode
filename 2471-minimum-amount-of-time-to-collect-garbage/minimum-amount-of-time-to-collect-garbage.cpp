class Solution {
public:
    int timetaken(vector<string> &garbage,vector<int> &travel,char material) {
        int ans = 0,n = garbage.size(),sum = 0;
        bool flag;
        for(int i=0 ; i<n ; ++i) {
            flag = false;
            for(int j=0 ; j<garbage[i].length() ; ++j) {
                if(garbage[i][j] == material) {
                    flag = true;
                    sum += 1;
                }
            }
            if(flag) ans = sum;
            if(i != n-1) sum += travel[i];
        }
        return ans;
    }

    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        ans += timetaken(garbage,travel,'P');
        ans += timetaken(garbage,travel,'G');
        ans += timetaken(garbage,travel,'M');
        return ans;
    }
};