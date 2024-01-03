class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0,ans = 0,n = bank.size(),m=bank[0].size();
        for(int i=0 ; i<n ; ++i) {
            int beam = 0;
            for(int j=0 ; j<m ; ++j) {
                if(bank[i][j] == '1') {
                    beam += 1;
                }
            }
            if(beam > 0) {
                ans += beam * prev;
                prev = beam;
            }
        }
        return ans;
    }
};