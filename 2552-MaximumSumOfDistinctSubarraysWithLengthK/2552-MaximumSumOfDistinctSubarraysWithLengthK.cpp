// Last updated: 8/31/2025, 10:48:41 AM
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        int i=0;
        int j=i+k-1;
        map<int, int>mpp;
        for (int it=i;it<=j;it++)
        {
            mpp[nums[it]]++;
            sum+=nums[it];
        }
        long long maxi=0;

        while (j<n)
        {
            if (mpp.size()==k)
            {
                maxi=max(maxi, sum);
            }
            sum-=nums[i];
            if (j!=n-1) sum+=nums[j+1];
            mpp[nums[i]]--;
            if (mpp[nums[i]]==0) mpp.erase(nums[i]);
            if (j!=n-1) mpp[nums[j+1]]++;
            i++;
            j++;
        }
        return maxi;
    }
};