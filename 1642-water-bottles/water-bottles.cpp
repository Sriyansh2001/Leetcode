class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int temp = 0;
        int ans = 0;
        while(numBottles > 0) {
            ans += numBottles;
            int t = (numBottles+temp)%numExchange; 
            numBottles = (numBottles+temp)/numExchange;
            temp = t;
        }
        return ans;
    }
};