// Last updated: 8/31/2025, 10:50:16 AM
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp;
        for (int i=0;i<n;i++)
        {
            vector<int> ret;
            for (int j=0;j<=i;j++)
            {
                if (i==0) ret.push_back(triangle[i][j]);
                else if (j==0) ret.push_back(triangle[i][j]+dp[i-1][j]);
                else if (i==j) ret.push_back(triangle[i][j]+dp[i-1][j-1]);
                else ret.push_back(triangle[i][j]+min(dp[i-1][j-1], dp[i-1][j]));
            }
            dp.push_back(ret);
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};