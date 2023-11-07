class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<double , vector<double> , greater<double>> q;
        int n = dist.size();

        for(int i=0 ; i<n ; ++i) {
            q.push((double)dist[i]/speed[i]);
        }

        int start = 0,result = 0;
        
        while(!q.empty()) {
            if(q.top() - start > 0) {
                result += 1;
            }
            else {
                return result;
            }
            start += 1;
            q.pop();
        }

        return result;
    }
};