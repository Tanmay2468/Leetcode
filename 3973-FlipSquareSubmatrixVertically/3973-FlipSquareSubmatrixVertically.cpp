// Last updated: 8/31/2025, 10:47:41 AM
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vec(m, vector<int>(n, 0));
        for (int i=x;i<m && i<x+k;i++){
            for (int j=y;j<n && j<y+k;j++){
                vec[i][j]=grid[i][j];
            }
        }
        // for (auto it: vec){
        //     for (auto i: it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        int r=x+k-1;
        for (int i=x;i<m && i<x+k;i++){
            for (int j=y;j<n && j<y+k;j++){
                grid[i][j]=vec[r][j];
            }
            r--;
        }
        return grid;
    }
};