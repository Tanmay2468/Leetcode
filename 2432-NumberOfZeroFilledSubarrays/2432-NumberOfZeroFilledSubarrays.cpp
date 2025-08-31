// Last updated: 8/31/2025, 10:48:46 AM
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ct=0, ans=0;
        int n=nums.size();
        for (int i=0;i<n;i++)
        {
            if (nums[i]==0) ct++;
            else
            {
                if (ct%2==0) ans+=(ct/2)*(ct+1);
                else ans+=(ct+1)/2*ct;
                ct=0;
            }
        }
        if (ct%2==0) ans+=(ct/2)*(ct+1);
        else ans+=(ct+1)/2*ct;
        return ans;
    }
};