// Last updated: 8/31/2025, 10:47:45 AM
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int peak=2;
        int prev=-1001;
        if (nums[0]>nums[1]) return false;
        for (int i=0;i<n;i++)
        {
            if (peak<0) return false;
            if (peak%2==0)
            {
                if (nums[i]<prev) peak--;
                else if (nums[i]==prev) return false;
                prev=nums[i];
            }
            else
            {
                if (nums[i]>prev) peak--;
                else if (nums[i]==prev) return false;
                prev=nums[i];
            }
        }
        if (peak==0) return true;
        return false;
    }
};