bool cmp(vector<int> &a,vector<int> &b){
    if(a[1]>=b[1]){
        return false;
    }
    return true;
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int ans=1,j=0;
        for(int i=1 ; i<pairs.size() ; i++){
            if(pairs[j][1]<pairs[i][0]){
                ans+=1;
                j=i;
            }
        }
        return ans;
    }
};