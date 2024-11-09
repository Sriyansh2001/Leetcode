class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        int i = 0;
        int k = n-1;
        while(k!=0) {
            if(!((res >> i) & 1)) {
                if(k&1) {
                    res = res | ((long long)1<<i);
                }
                k = k>>1;
            }
            i+=1;
        }
        return res;
    }
};