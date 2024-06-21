class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0, extra = 0, extra_max = 0;
        int n = grumpy.size();
        for(int i=n-1 ; i>=0 ; --i) {
            if(!grumpy[i]) {
                ans += customers[i];
            } 
            else {
                extra = customers[i] + extra;   
            }   
            int k = i+minutes;
            if(k < n && grumpy[k]) {
                extra -= customers[k];
            }
            extra_max = max(extra,extra_max);
        }
        return extra_max + ans;
    }
};