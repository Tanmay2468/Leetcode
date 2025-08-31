// Last updated: 8/31/2025, 10:48:28 AM
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int hor_min=INT_MIN, hor_max=INT_MIN, vert_min=INT_MIN, vert_max=INT_MIN;
        int n=grid.size();
        int m=grid[0].size();
        bool hor=false, vert=false;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (grid[i][j]==1 && !hor && !vert)
                {
                    hor_min=i;
                    hor_max=i;
                    vert_min=j;
                    vert_max=j;
                    hor=true;
                    vert=true;
                }
                if (grid[i][j]==1)
                {
                    hor_min=min(hor_min, i);
                    hor_max=max(hor_max, i);
                    vert_min=min(vert_min, j);
                    vert_max=max(vert_max, j);
                }
            }
        }
        if (vert && hor)
        {
            return (hor_max-hor_min+1)*(vert_max-vert_min+1);
        }
        return 0;
    }
};