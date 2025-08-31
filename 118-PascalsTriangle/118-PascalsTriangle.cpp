// Last updated: 8/31/2025, 10:50:17 AM
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for (int i=1;i<=numRows;i++)
        {
            if (i==1)
            {
                pascal.push_back({1});
                continue;
            }
            else if (i==2)
            {
                pascal.push_back({1, 1});
                continue;
            }
            vector<int> row(i, 1);
            for (int j=1;j<=i-2;j++)
            {
                row[j]=pascal[i-2][j-1]+pascal[i-2][j];
            }
            pascal.push_back(row);
        }
        return pascal;
    }
};