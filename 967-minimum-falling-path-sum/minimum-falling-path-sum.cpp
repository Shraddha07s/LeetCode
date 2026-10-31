class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix;

        for(int r=n-2; r>=0; r--){
            for(int c=0; c<n; c++){
                int bestBelow = dp[r+1][c];

                if(c>0){
                    bestBelow = min(bestBelow,dp[r+1][c-1]);
                }
                if(c+1 < n){
                    bestBelow = min(bestBelow, dp[r+1][c+1]);
                }
                dp[r][c] += bestBelow ;
            }
        }
        return * min_element(dp[0].begin(), dp[0].end());
    }
};