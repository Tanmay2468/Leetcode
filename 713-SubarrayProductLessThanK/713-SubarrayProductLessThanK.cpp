// Last updated: 8/31/2025, 10:49:42 AM
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0, ct=0, prod=1;
        for (int right=0;right<n;right++)
        {
            prod*=nums[right];
            while (left<=right && prod>=k)
            {
                prod/=nums[left];
                left++;
            }
            ct+=right-left+1;
        }
        return ct;
    }
};