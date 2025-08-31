// Last updated: 8/31/2025, 10:48:59 AM
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s=original.size();
        vector<vector<int>> vec(m,vector<int>(n));
        int ct=0;
        if (s==m*n)
        {
            for (int i=0;i<m;i++)
            {
                for (int j=0;j<n;j++)
                {
                    vec[i][j]=original[ct];
                    ct++;
                }
            }
        }
        else
        {
            return {};
        }
        return vec;
    }
};