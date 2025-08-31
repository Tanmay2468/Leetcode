// Last updated: 8/31/2025, 10:48:02 AM
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i=0;i<n;i++)
        {
            int j=i, k=0;
            vector<int> temp;
            while (j<n && k<n)
            {
                temp.push_back(grid[j][k]);
                j++;
                k++;
            }
            sort(temp.begin(), temp.end(), greater<int>());
            j=i, k=0;
            int idx=0;
            while (j<n && k<n)
            {
                ans[j][k]=temp[idx++];
                j++;
                k++;
            }
        }
        for (int i=1;i<n;i++)
        {
            int j=0, k=i;
            vector<int> temp;
            while (j<n && k<n)
            {
                temp.push_back(grid[j][k]);
                j++;
                k++;
            }
            sort(temp.begin(), temp.end());
            j=0, k=i;
            int idx=0;
            while (j<n && k<n)
            {
                ans[j][k]=temp[idx++];
                j++;
                k++;
            }
        }
        return ans;
    }
};