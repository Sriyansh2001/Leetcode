class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, sum = 0,ans=0,n = arr.size(),even = 1;
        for(int i=0 ; i<n ; ++i) {
            sum+=arr[i];
            if(sum%2==0) {
                even++;
                ans=(ans+odd)%M;
            } else {
                odd++;
                ans=(ans+even)%M;
            }
        }
        return ans;
    }
};