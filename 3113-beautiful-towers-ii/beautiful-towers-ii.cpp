class Solution {
public:
    vector<int> next_smaller(vector<int> &nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=n-1 ; i>=0 ; --i) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> prev_smaller(vector<int> &nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=0 ; i<n ; ++i) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long ans = 0;
        int n = maxHeights.size();

        vector<long> storageleft(n,0),storageright(n,0);
        vector<int> left = prev_smaller(maxHeights);
        vector<int> right = next_smaller(maxHeights);

        long sum = 0;

        for(int i=0 ; i<n ; ++i) {
            if(left[i] == -1) {
                storageleft[i] = maxHeights[i]*1LL*(i+1);
            }
            else {
                int ind = left[i];
                storageleft[i] = storageleft[ind]+(i-ind)*1LL*maxHeights[i];
            }
        }

        for(int i=n-1 ; i>=0 ; --i) {
            if(right[i] == -1) {
                storageright[i] = maxHeights[i]*1LL*(n-i);
            }
            else {
                int ind = right[i];
                storageright[i] = storageright[ind] + (ind-i)*1LL*maxHeights[i];
            }
        }

        ans = max(storageright[0],storageleft[n-1]);
        for(int i=1 ; i<n-1 ; ++i) {
            ans = max(storageright[i]+storageleft[i]-maxHeights[i],ans);
        }

        return ans;
    }
};