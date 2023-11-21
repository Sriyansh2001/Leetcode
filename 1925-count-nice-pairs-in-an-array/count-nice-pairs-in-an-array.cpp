class Solution {
public:
    int mod= 1e9+7;
    int rev(int n){
        int ans=0;
        while(n){
            int a = n%10;
            ans  = ans*10 + a;
            n=n/10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i  : nums){
            mp[i-rev(i)]+=1;
        }
        long ans=0;
        for(auto i : mp){
            long a = i.second;

            ans+= ((a *(a-1))/2)%mod;
        }

        return ans%mod;
    }
};