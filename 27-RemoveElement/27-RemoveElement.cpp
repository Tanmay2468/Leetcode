// Last updated: 8/31/2025, 10:50:32 AM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int ct=0;
        for (int i=0;i<n;i++)
        {
            if (nums[i]!=val)
            {
                nums[ct]=nums[i];
                ct++;
            }
        }
        return ct;
    }
};