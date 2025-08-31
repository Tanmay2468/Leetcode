// Last updated: 8/31/2025, 10:48:30 AM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int Xor=0;
        unordered_map<int, int> mpp;
        vector<int> ans(2);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                Xor^=grid[i][j];
                mpp[grid[i][j]]++;
            }
        }
        for (auto it: mpp) if (it.second==2) ans[0]=it.first;
        for (int i=1;i<=pow(n, 2);i++) Xor^=i;
        Xor^=ans[0];
        ans[1]=Xor;
        return ans;
    }
};