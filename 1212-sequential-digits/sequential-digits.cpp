class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        vector<int> ans;

        for (int i = 0; i < str.size(); i++) {
            for (int j = i, temp = 0; j < str.size(); j++) {
                temp = temp * 10 + (str[j] - '0');

                if (temp <= high && temp >= low)
                    ans.push_back(temp);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};