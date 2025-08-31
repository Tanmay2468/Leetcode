// Last updated: 8/31/2025, 10:48:57 AM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (abs(grid[0][0]-grid[i][j])%x!=0) return -1;
            }
        }
        vector<int> vec;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin(), vec.end());
        int median=n*m/2;
        int ct=0;
        for (auto it: vec)
        {
            ct+=abs(it-vec[median])/x;
        }
        return ct;
    }
};