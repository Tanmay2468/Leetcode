// Last updated: 8/31/2025, 10:48:25 AM
class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n=maximumHeight.size();
        sort(maximumHeight.begin(), maximumHeight.end());
        long long ans=0;
        long long ct=maximumHeight[n-1];
        for (int i=n-1;i>=0;i--)
        {
            ct=min(ct, (long long)maximumHeight[i]);
            if (ct<=0) return -1;
            ans+=ct;
            ct--;
        }
        return ans;
    }
};