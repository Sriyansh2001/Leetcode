class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), close = 0, open = 0, total, ans = 0, penalty;
        
        for(int i=0 ; i<n ; ++i) {
            if(customers[i] == 'Y') open+=1;
        }

        penalty = open;

        for(int i=0 ; i<n ; ++i) {
            if(customers[i] == 'Y') open-=1;
            if(customers[i] == 'N') close+=1;
            total = open+close;
            if(total < penalty) {
                penalty = total;
                ans = i+1;
            }
        }

        return ans;
    }
};