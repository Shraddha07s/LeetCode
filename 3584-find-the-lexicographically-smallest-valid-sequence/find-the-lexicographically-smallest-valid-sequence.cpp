class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> dp(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {

            if (j >= 0 && word1[i] == word2[j]) {
                dp[i] = dp[i + 1] + 1;
                j--;
            }
            else {
                dp[i] = dp[i + 1];
            }
        }

        vector<int> ans;

        int i = 0;
        j = 0;

        bool mismatchUsed = false;

        while (i < n && j < m) {

            if (word1[i] == word2[j]) {

                ans.push_back(i);
                i++;
                j++;
            }

            else if (!mismatchUsed &&
                     dp[i + 1] >= m - j - 1) {

                ans.push_back(i);

                mismatchUsed = true;

                i++;
                j++;
            }

            else {
                i++;
            }
        }

        if (j != m)
            return {};

        return ans;
    }
};