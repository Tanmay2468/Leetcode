// Last updated: 8/31/2025, 10:49:13 AM
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int y=n*(n+1)/2;
        vector<long long> arr;
        for (int i=0;i<n;i++)
        {
            long long sum=0;
            for (int j=i;j<n;j++)
            {
                sum+=nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(),arr.end());
        long long ans=0;
        for (int i=left-1;i<right;i++)
        {
            ans+=arr[i];
        }
        long long qw=pow(10,9)+7;
        long long q=ans%qw;
        return q;
    }
};