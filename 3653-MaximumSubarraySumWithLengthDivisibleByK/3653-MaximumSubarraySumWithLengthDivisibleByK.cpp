// Last updated: 8/31/2025, 10:48:05 AM
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // int sz=n+1-k;
        // vector<long long> arr(sz);
        // long long sum=0;
        // for (int i=0;i<k-1;i++){
        //     sum+=nums[i];
        // }
        // long long maxi=INT_MIN;
        // for (int i=0;i<=n-k;i++){
        //     sum+=nums[i+k-1];
        //     arr[i]=sum;
        //     maxi=max(maxi, arr[i]);
        //     sum-=nums[i];
        // }
        // int newK=k;
        // return sum;

        vector<int>res=nums;
        int n=nums.size();
        long long sum=0;
        vector<long long> prefix(n+1, 0);
        for (int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        vector<long long> minpre(k, LLONG_MAX);
        long long m=LLONG_MIN;
        for (int i=0;i<=n;i++){
            int rem=i%k;
            if (i>=k){
                m=max(m, prefix[i]-minpre[rem]);
            }
            minpre[rem]=min(minpre[rem], prefix[i]);
        }
        if (m==LLONG_MIN) return 0;
        else return m;
    }
};