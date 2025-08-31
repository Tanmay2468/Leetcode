// Last updated: 8/31/2025, 10:47:42 AM
class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        vector<int> arr=nums;
        int n=nums.size();
        vector<long long> pre(n+1, 0);
        for (int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }
        vector<long long> dp(n+1, LLONG_MAX);
        dp[0]=0;
        vector<long long> best(k, LLONG_MAX);
        best[0]=0;
        for (int i=1;i<=n;i++){
            int rem=pre[i]%k;
            dp[i]=dp[i-1]+nums[i-1];
            if (best[rem]!=LLONG_MAX) dp[i]=min(dp[i], best[rem]);
            best[rem]=min(best[rem], dp[i]);
        }
        return dp[n];
    }
};