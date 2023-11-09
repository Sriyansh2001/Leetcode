class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0;
        int n = s.length();
        int i=0;

        while(i<n) {
            char c = s[i];
            long long count = 0;
            while(i<n && s[i] == c) {
                i+=1;
                count += 1;
            }
            ans = ans + (count*(count+1))/2;
        }

        return ans%((int)1e9+7);
    }
};