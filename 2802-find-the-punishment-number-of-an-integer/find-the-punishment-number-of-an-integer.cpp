class Solution {
public:
    bool checkSum(int n, int total) {
        if(total < 0) return false;
        if(0 == total) {
            return n == 0;
        }
        bool ans = false;
        int res = 0, rem = 0;
        int divide = 1;
        while(n/divide != 0) {
            res = n / divide;
            rem = n % divide;
            divide *= 10;
            ans |= checkSum(rem, total - res);
        }
        return ans;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1 ; i<=n ; ++i) {
            bool k = checkSum(i*i, i);
            if(k) {
                ans += i*i;
            }
        }
        return ans;
    }
};