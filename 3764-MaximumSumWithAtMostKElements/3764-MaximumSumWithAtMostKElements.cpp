// Last updated: 8/31/2025, 10:48:00 AM
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n=grid.size();
        int m=grid[0].size();
        // cout<<n<<m;
        vector<int> arr;
        for (int i=0;i<n;i++){
            sort(grid[i].begin(), grid[i].end());
            int lim=limits[i];
            for (int j=m-1;j>=0 && lim>0;j--){
                arr.push_back(grid[i][j]);
                lim--;
            }
            // for (auto it: arr) cout<<it<<" ";
            // cout<<endl;
        }
        sort(arr.begin(), arr.end());
        long long sum=0;
        int sz=arr.size();
        int p=k;
        int tt=sz-1;
        while (p--){
            sum+=arr[tt];
            tt--;
        }
        return sum;
    }
};