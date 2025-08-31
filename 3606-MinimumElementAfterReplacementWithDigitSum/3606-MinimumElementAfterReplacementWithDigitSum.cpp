// Last updated: 8/31/2025, 10:48:17 AM
class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        for (int i=0;i<n;i++)
        {
            long long int ans=0;
            int temp=nums[i];
            while (temp>0)
            {
                ans+=temp%10;
                temp/=10;
            }
            nums[i]=ans;
        }
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};