class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<vector<int>> temp;
        int n = nums.size();
        for(int i=0 ; i<n ; ++i) {
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        priority_queue<int,vector<int> , greater<int>> q;
        int i=0;
        while(i<n) {
            vector<int> ind;
            int j=i;
            q.push(temp[j][1]);
            while(j<n) {
                if(j!=n-1) {
                    if(temp[j+1][0]-temp[j][0] <= limit) {
                        q.push(temp[j+1][1]);
                    }
                    else break;
                }
                j+=1;
            }
            while(!q.empty()) {
                nums[q.top()] = temp[i][0];
                q.pop();
                i+=1;
            }
        }
        return nums;
    }
};